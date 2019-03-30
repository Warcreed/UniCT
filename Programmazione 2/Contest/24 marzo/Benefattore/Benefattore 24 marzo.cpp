#include<fstream>
#include<iomanip>
using namespace std;

int main(){

const int DIM=100;
ifstream in("input.txt");
ofstream out("output.txt");


for(int i=0; i<DIM; i++){
    int N=0;
    float sum=0,maxK=0,peso=0;
    in >> maxK >> N;
    float vett[N]={0};
    in >> vett[0];

    for(int j=1; j<N; j++){
        in >> peso;
        bool flag=true;

        for(int k=0; k<N && flag; k++){
            if(peso<vett[k]){
                flag=false;

                for(int l=N-1; l>k; l--)
                    vett[l]=vett[l-1];

                vett[k]=peso;
            }
        }
        if(flag)
        vett[j]=peso;
    }
        int l=0;
        while(sum+vett[l+1]<=maxK && l<N){
            sum+=vett[l++];
        }
        out << l << " " << sum << endl;

}
return 0;
}

