#include<fstream>
using namespace std;

string swap(string s, int i,int j){
    char temp=s[i];
    s[i]=s[j];
    s[j]=temp;
    return s;
}

int main(){
const int DIM = 100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    string word="", text="";
    in >> word;
    in >> text;                                                         //prelevo la parola da cercare e il testo

    bool scambio=false;
    for(int j=0; j<=text.length()-word.length();j++){

        string temp = text.substr(j,word.length());                     //prendo una sottostringa dal testo
        scambio=false;
        for(int k=0; k<word.length()-1; k++)                            //ciclo di controllo
                if(temp[k]!=word[k] && temp[k+1]==word[k] && !scambio){ //se la corrispettiva lettera non è uguale controllo quella adicente a destra
                    temp=swap(temp,k,k+1);                              //se è uguale faccio swap e setto a true in modo da ricordare lo swap effettuato
                    scambio=true;
                } else scambio=false;                                   //eventualmente risetto a false la variabile per permettere uno scambio

        if(word==temp)                                                  //se le parole sono uguali, stampo su file l'indice j
            out << j << " ";
    }
    out << endl;
}
return 0;
}
