#include<fstream>
#include<iomanip>
using namespace std;

int main(){
const int DIM=100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    int N=0;
    in >> N;
    float vett[N]={0};
    for(int j=0; j<N; j++)
        in >> vett[j];


    float guadagno=0;
    for(int j=0; j<N; j++)
        for(int k=j+1; k<N; k++)
            if(vett[k]-vett[j]>guadagno) guadagno=vett[k]-vett[j];

    out << setprecision(4)<<guadagno << endl;
}
return 0;
}

