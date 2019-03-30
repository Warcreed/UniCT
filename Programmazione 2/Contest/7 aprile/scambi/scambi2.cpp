#include<fstream>
using namespace std;

int main(){
const int DIM = 100;
ifstream in("input.txt");
ofstream out("output1.txt");

for(int i=0; i<DIM; i++){
    string word="", text="";
       in >> word;
       in >> text;

    //presi i due input mi accingo a controllare dove la parola sia presente
    bool flag=false, trovata;
    int counter=0;
    //questo for viene usato per scorrere il testo fino alla sua lunghezza meno quella della parola da trovare
    for(int j=0; j<=text.length()-word.length();j++){
            counter=0;

            //isolo una stringa del testo con la lunghezza della parola
            string temp = text.substr(j,word.length());
            //comparo la parola data con la sottostringa prelevata
        for(int k=0; k<word.length(); k++){
                trovata=false;
                //controllo se è il primo carattere, per cui controllo solo la posizione k e k+1 (k-1 non ha senso)
                if(k==0){
                    for(int l=k; l<=k+1 && !trovata; l++)
                        if(temp[l]==word[k]){ trovata=true; temp[l]='T';} //sostituisco T come carattere speciale per ovviare alla questione della lettere ripetute.
                }
                //se non è il primo controllo se è l'ultimo (sempre per il discorso di prima)
                else if(k==word.length()-1){
                    for(int l=k; l>=k-1 && !trovata; l--)
                        if(temp[l]==word[k]){ trovata=true; temp[l]='T';}
                }
                //altrimenti è un carattere del mezzo e controllo il suo corrispettivo, quello precedente e quello successivo (esclusione, se lo trovo gli altri non li guarda)
                else{
                        if(temp[k]==word[k] && !trovata){ trovata=true; temp[k]='T';}
                        if(temp[k-1]==word[k] && !trovata){ trovata=true; temp[k-1]='T';}
                        if(temp[k+1]==word[k] && !trovata){ trovata=true; temp[k+1]='T';}

                }
            //se trovata è stato settato a true vuol dire che la lettera è stata trovata, incremento il num di lettere
            if(trovata)
                counter++;
        }

        //se counter corrisponde con la lunghezza della stringa, ho trovato una parola e ne stampo le coordinate
            if(counter==word.length()){
                if(!flag){
                    out << j;
                    flag=true;
                }else out << " " << j;
            }
    }
    out << endl;
}
return 0;
}

