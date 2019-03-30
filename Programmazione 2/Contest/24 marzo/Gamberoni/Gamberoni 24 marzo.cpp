#include<fstream>
#include<iomanip>
using namespace std;

int main(){
const int DIM=10;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    int indice=0, N=0;
    float min=100.0,max=0.0;
    in >> N;
    float vett[N]={0};
    for(int j=0; j<N; j++){
        in >> vett[j];
        if(vett[j]<min){
            min=vett[j];
            indice=j;
        }
    }
    for(int l=indice+1; l<N; l++)
        if(vett[l]>max) max=vett[l];

    float ris=(max>min)?max-min:0;
    out << ris << endl;
}
return 0;
}
