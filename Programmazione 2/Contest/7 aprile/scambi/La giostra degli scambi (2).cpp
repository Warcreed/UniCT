#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output1.txt");
	int n=100; //numero di righe del file in input
	string parola,frase,temp,perfetto;
	char temp_char;
	bool flag;

	   for(int i=0;i<n;i++)
	   {
	   	    fin>>parola;
	   	    fin>>temp;

	   	    	  	 	for(int w=0; w<=temp.length()-parola.length();w++)
	   	    	  	 	{
	   	    	  	 		perfetto=temp.substr(w,parola.length()); //ogni possibile sottostringa
							flag=true;	   //flag è utilizzato per capire se un carattere non è stato trovato
	   	    	  	 		for(int k=0;k<perfetto.length();k++) //controllo interamente la sottostringa
		   	    	  	 	{
		   	    	  	 		if(perfetto[k]!=parola[k]) //se il carattere della sott. coincide con il carattere della parola, non devo fare nulla
								 if(perfetto[k]==parola[k+1] && perfetto[k+1]==parola[k]) //se diagonalmente sono diversi, ovvero: as   sa
								 { //faccio uno scambio, alla prossima esecuzione sicuramente il carattere k sarà uguale a quello della parola
								 	temp_char=perfetto[k];
								 	perfetto[k]=perfetto[k+1];
								 	perfetto[k+1]=temp_char;
								 }
								 else //ho trovato un carattere che non c'entra nulla
								  {
								  	flag=false;
								  	break;
								  }
							}

							if(flag) //Se il flag è sempre rimasto true, allora stampo la posizione del primo carattere della sottostringa
							 	fout<<w<<" ";
						}
	   	    	  	 		 fout<<endl;
		}

    fout.close();
	fin.close();
}
