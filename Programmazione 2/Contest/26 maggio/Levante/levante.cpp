#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    const int DIM=1;
for(int i=0; i<DIM; i++){
    int Nodi=0, Canali=0, MinutiMarea=0;
    in >> Nodi >> Canali >> MinutiMarea;

    int Map[Nodi][Nodi]={};
    int minRoot[Nodi][Nodi]={};

    for(int j=0; j<Canali; j++){
        int temp, temp1;
        in >> temp >> temp1;
        Map[temp][temp1]=1;
    }
    cout<< " ";
    for(int j=0; j<Nodi; j++)
            cout << " " << j;
    cout<<endl;
     for(int j=0; j<Nodi; j++){
        cout << j << " ";
        for(int k=0; k<Nodi; k++)
            cout << Map[j][k] << " ";
        cout << endl;
     }
    cout << endl << endl;
   for(int j=0; j<Nodi; j++){
        for(int k=0; k<Nodi; k++){
            if(Map[j][k]==1)
                   {
                       Map[j][k]=0;
                       Map[k][j]=2;
                   }
             cout << Map[j][k] << " ";
        }
cout << endl;
        }



}
return 0;
}
