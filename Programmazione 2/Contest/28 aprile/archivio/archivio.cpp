#include<fstream>
using namespace std;

swap(int* v,int i,int j){
    int temp = v[i];
    v[i]=v[j];
    v[j]=temp;
}
int main(){

const int DIM=100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    int N=0;
    in >> N;
    int v[N];
    for(int j=0; j<N; j++)
        in >> v[j];

    bool scambi;
    int Nscambi=0;
    do{
        scambi=false;
        for(int k=1; k<N-1; k++)
            if(v[k-1]>v[k+1]){
                swap(v,k-1,k+1);
                scambi=true;
                Nscambi++;
            }
    }while(scambi);

    out << Nscambi << endl;
}
return 0;
}

