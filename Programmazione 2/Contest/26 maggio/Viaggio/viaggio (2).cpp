#include<fstream>
#include<iostream>
using namespace std;

class Passeggero{
public:
    int passeggero;
    int posto;

    Passeggero( int pass, int post) : passeggero(pass), posto(post){}
    Passeggero() : passeggero(-1), posto(-1){}

};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    const int DIM=100;
    Passeggero* postoVuoto = new Passeggero();
for(int i=0; i<DIM; i++){
    int N=0, sol=0;
    in >> N;

    Passeggero* posto[N];
    for(int j=0; j<N; j++){
        posto[j] = new Passeggero();
    }

    int azioni=0;
    in >> azioni;
    char a;
    for(int j=0; j<azioni; j++){
            int postopass=-1;
            in >> a;
            in >> postopass;
            Passeggero* p= new Passeggero(j,postopass);
            if(a=='b'){
                int k=0;
                while(posto[k]->posto!=-1 && k!= p->posto){k++;}
                if(posto[k]->posto==-1) posto[k]=p;
                else{
                    bool flag=false;
                    Passeggero* temp;
                    while(!flag){
                        temp = posto[k];
                        posto[k]= p;
                        if(posto[temp->posto]->posto==-1){
                            posto[temp->posto]=temp;
                            flag=true;
                        }
                        else{
                            k=temp->posto;
                            p=temp;
                        }
                        sol++;
                    }
                }
            }
            else{
                for(int k=0; k<N; k++)
                    if(posto[k]->posto==postopass) posto[k] = postoVuoto;
            }
    }
    out << sol << endl;
}
return 0;
}
