#include "stm32_unict_lib.h"
#include <stdio.h>

#define DIM_SERBATOIO 300

enum {
	S_RUN,
	S_RAINING
};

int stato = S_RUN;

int serbatoio = 0;
int dimensione_goccia;
int frequenza_pioggia;
int lampeggio_led = 0;

int main(){
    CONSOLE_init();
    DISPLAY_init();
	GPIO_init(GPIOB);
	GPIO_init(GPIOC);

	GPIO_config_output(GPIOB, 0);
	GPIO_config_output(GPIOC, 2);
	DISPLAY_dp(2,1);

	//x
	GPIO_config_input(GPIOB, 10);
	GPIO_config_EXTI(GPIOB, EXTI10);
	EXTI_enable(EXTI10, FALLING_EDGE);

	ADC_init(ADC1, ADC_RES_6, ADC_ALIGN_RIGHT);
	ADC_channel_config(ADC1, GPIOC, 1, 11);
	ADC_channel_config(ADC1, GPIOC, 0, 10);
	ADC_on(ADC1);

	TIM_init(TIM2);
	TIM_config_timebase(TIM2, 42000, 200);
	TIM_enable_irq(TIM2, IRQ_UPDATE);
	TIM_set(TIM2, 0);
	TIM_on(TIM2);

    for(;;){
    	char dysp[5];
    	switch(stato){
    		case S_RUN:
    			GPIO_write(GPIOB, 0, 0);
    			GPIO_write(GPIOC, 2, 0);
    			printf("Aspettando la pioggia...\n");
    			break;
    		case S_RAINING:
    			GPIO_write(GPIOB, 0, 1);
    			if(++lampeggio_led > 20)
    				GPIO_write(GPIOC, 2, 0);

    			ADC_sample_channel(ADC1, 11); //frequenza pioggia
    			ADC_start(ADC1);
    			while (!ADC_completed(ADC1)){}
    			frequenza_pioggia = 1800 - (ADC_read(ADC1) * (1600 - 200) / 63 + 200)	;

    			ADC_sample_channel(ADC1, 10); //dimensione goccia
    			ADC_start(ADC1);
    			while (!ADC_completed(ADC1)){}
    			dimensione_goccia = (ADC_read(ADC1) * ((float)(50 - 2) / 63)) + 2;
    			printf("Piove! dim_goccia: %d, frequenza: %d\n", dimensione_goccia, frequenza_pioggia);
    			break;
    		default:
    			break;
    	}
    	if(serbatoio > DIM_SERBATOIO){
    		serbatoio = 0;
    		printf("Svuotamento\n");
    	}
        sprintf(dysp, "%.4d", serbatoio);
		DISPLAY_puts(0, dysp);
    }
}

//x
void EXTI15_10_IRQHandler(){
	if (EXTI_isset(EXTI10)){
		if(stato == S_RUN)
			stato = S_RAINING;
		else
			stato = S_RUN;
		EXTI_clear(EXTI10);
	}
}

void TIM2_IRQHandler(){
	if (TIM_update_check(TIM2)){
		if(stato == S_RAINING){
			serbatoio += dimensione_goccia;
			TIM2->ARR = frequenza_pioggia;
			lampeggio_led = 0;
			GPIO_write(GPIOC, 2, 1);
		}
		TIM_update_clear(TIM2);
	}
}
