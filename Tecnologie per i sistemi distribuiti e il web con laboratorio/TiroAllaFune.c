#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t player_one = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t player_two = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int posizione = 0;
int vittorie_tp0 = 0;
int vittorie_tp1 = 0;

void first_player()
{
    while (vittorie_tp0 < 10 || vittorie_tp1 < 10)
    {
        int recupero = rand() % 4;
        int forza = rand() % 6;
        sleep(recupero);
        if (posizione >= 10)
        {
            pthread_mutex_lock(&mutex);
            ++vittorie_tp1;
            posizione = 0;
            pthread_mutex_unlock(&mutex);
            pthread_mutex_unlock(&player_two);
        }else{
            pthread_mutex_lock(&mutex);
            posizione -= forza;
            pthread_mutex_unlock(&mutex);
            if(posizione <= -10)
                pthread_mutex_lock(&player_one);
        }   
    }
    pthread_exit(NULL);
}

void second_player()
{
    while (vittorie_tp1 < 10 || vittorie_tp0 < 10)
    {
        int recupero = rand() % 4;
        int forza = rand() % 6;
        sleep(recupero);
        if (posizione <= -10)
        {
            pthread_mutex_lock(&mutex);
            ++vittorie_tp0;
            posizione = 0;
            pthread_mutex_unlock(&mutex);
            pthread_mutex_unlock(&player_one);
        }else{
           pthread_mutex_lock(&mutex);
            posizione += forza;
            pthread_mutex_unlock(&mutex);
            if(posizione >= 10)
                pthread_mutex_lock(&player_two);
        }   
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t tp[2];
    srand(time(NULL));
    pthread_create(&tp[0], NULL, (void*) &player_one, ((void *)0));
    pthread_create(&tp[1], NULL, (void*) &player_two, ((void *)0));

    pthread_join(tp[0], NULL);
    pthread_join(tp[1], NULL);
    if(vittorie_tp0 > vittorie_tp1)
        printf("first player ha vinto con %d vittorie", vittorie_tp0);
    else
        printf("second player ha vinto con %d vittorie", vittorie_tp1);
    exit(0);
}