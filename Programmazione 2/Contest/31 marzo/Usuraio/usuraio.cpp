#include<fstream>
#include<cstdlib>
#include<iostream>
using namespace std;

void InserimentoOrdinato(int* vett, int N, istream& in){
    int Ncivico=0;
    for(int j=1; j<N; j++){
        in >> Ncivico;
        bool flag=true;
        for(int k=0; k<N && flag; k++){
            if(Ncivico<vett[k]){
                flag=false;

                for(int l=N-1; l>k; l--)
                    vett[l]=vett[l-1];

                vett[k]=Ncivico;
            }
        }
        if(flag)
        vett[j]=Ncivico;
    }
    for(int j=0; j<N; j++){
            cout << vett[j] << endl;
        }
}
int main(){

const int DIM=3;
ifstream in("input.txt");
ofstream out("output.txt");


for(int i=0; i<DIM; i++){
    int N=0, K=0, min = RAND_MAX, dist=0;
    in >> N >> K;
    int vett[N]={0};
    in >> vett[0];

    InserimentoOrdinato(vett, N, in);
    cout << "N=" << N << "\tK=" << K << endl;

       for(int j=0; j<=N-K; j++){
            dist=0;
            bool flag= false;
            cout << j << ") min=" << min << endl;
            for(int k=K-1; j+k>j; k--){
                dist+=vett[j+k]-vett[j+k-1];
                flag=true;
                cout << "\tdist=" << dist << endl;
            }

            if(dist<min && flag) min=dist;
           // cout << j << ") min=" << min << "\tdist=" << dist << endl;
        }

        cout << endl << "min= " << min << endl << endl;



}
return 0;
}

