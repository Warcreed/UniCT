#include<fstream>
#include<iostream>

using namespace std;

int main(){
const int DIM = 100;
const int dim=3;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    int N=0, puntoB=0, puntoC=0;
    char scarto;
    in >> N;
    for(int j=0; j<N; j++){
        int game[dim][dim] = {0};

        int x=0, y=0, counter=0,  brancata=1, carcannazzu=1;
        bool fineGame=false;
        do{

            in >> scarto >> x >> scarto >> y >> scarto;
            (counter%2 == 0)? game[x][y]=1 : game[x][y]=2;
            counter++;

            int brancata=0, carcannazzu=0;
            for(int k=0;k<dim*2 && !fineGame;k++){
                brancata=0, carcannazzu=0;
                for(int l=0;l<dim;l++){
                     if(k<dim){
                        if(game[k%dim][l]==1) brancata++;             //controllo righe
                        else if(game[k%dim][l]==2)carcannazzu++;
                     }
                     else{
                        if(game[l][k%dim]==1) brancata++;             //controllo colonne
                        else if(game[l][k%dim]==2)carcannazzu++;
                     }
                }

                if(brancata==3){
                    fineGame=true;
                    puntoB++;
                }
                else if(carcannazzu==3){
                    fineGame=true;
                    puntoC++;
                }
            }


            //controllo diagonali

            for(int k=0;k<dim*2 && !fineGame;k++){
                if(k%dim==0) {brancata=0, carcannazzu=0;}
                if(k<dim){
                    if(game[k%dim][k%dim]==1) brancata++;
                    else if(game[k%dim][k%dim]==2) carcannazzu++;
                }
                else{
                    if(game[k%dim][dim-k%dim-1]==1) brancata++;
                    else if(game[k%dim][dim-k%dim-1]==2) carcannazzu++;
                }
                if(brancata==3){
                    fineGame=true;
                    puntoB++;
                }
                else if(carcannazzu==3){
                    fineGame=true;
                    puntoC++;
                }
            }

        }while(!fineGame && counter<dim*dim);


    }
    out << puntoB << " " << puntoC << endl;
}
return 0;
}
