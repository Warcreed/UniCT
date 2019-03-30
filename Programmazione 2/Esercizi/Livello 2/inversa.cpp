#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    const int DIM=2;
for(int i=0; i<DIM; i++){
    int N=0;
    in >> N;
    int a, b;
    float su=0, giu=0;

    for(int j=0; j<N; j++){
        in >> a >> b;
        su=0;
        giu=(a>=b)? a : b;
        bool found=false;

        do{
                su++;
                giu--;

        }while(!((su+giu==a && giu/su==b) || (su+giu==a && giu-su==b) || (su+giu==b && giu/su==a) || (su+giu==b && giu-su==a) || (giu/su==a && giu-su==b) || (giu/su==a && giu+su==b)));
         cout << giu <<" " << su << " "<< endl;
    }
    cout << endl;
}
return 0;
}
