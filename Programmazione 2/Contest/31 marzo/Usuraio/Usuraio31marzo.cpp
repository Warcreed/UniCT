#include<fstream>
#include<cstdlib>
using namespace std;

void InserimentoOrdinato(int* vett, int N, istream& in){
    int Ncivico=0;
    for(int j=0; j<N; j++){
        in >> Ncivico;
        bool flag=true;
        for(int k=0; k<j && flag; k++){
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
}

int main(){

const int DIM=100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    int N=0, K=0, min = RAND_MAX, dist=0;
    in >> N >> K;
    int vett[N]={0};
    in >> vett[0];

    InserimentoOrdinato(vett, N, in);

       for(int j=0; j<=N-K; j++){
            dist=0;
            bool flag= false;
            for(int k=K-1; j+k>j; k--){
                dist+=vett[j+k]-vett[j+k-1];
                flag=true;
            }

            if(dist<min && flag) min=dist;
        }

        out << min << endl;

}
return 0;
}
