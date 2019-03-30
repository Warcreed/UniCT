#include<fstream>
#include<iostream>

using namespace std;

void swap(int* v, int j, int k){
    int temp=v[j];
    v[j]=v[k];
    v[k]=temp;
}
int main(){

    const int DIM=100;
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<DIM; i++){
        int N=0, sum=0;
        in >> N;
        int v[N];

        for(int j=0; j<N; j++)
            in >> v[j];
    int min=101, pos=0;
        for(int j=0; j<N; j++){
            for(int k=j+1; k<N; k++){
                if(v[k]<v[j] && v[k]<min){
                   min=v[j];
                   pos=k;
                }
            }
        swap(v,j,pos);
        sum+=pos-j;
        }

        out << sum << endl;

//        for(int j=0; j<N; j++)
//            cout <<  v[j] << " ";
//
//        cout <<endl;

    }
return 0;
}
