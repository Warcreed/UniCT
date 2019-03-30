#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int DIM=10;
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int l=0; l<DIM; l++){
        int N=0, M=0;
        in >> N;
        in >> M;
        int A[N], B[M], C[N+M];
        for(int j=0; j<N; j++){
            in >> A[j];
        }
        for(int j=0; j<M; j++){
            in >> B[j];
        }
        int i=0, k=0,count=0;
        for(int i=0; i<M; i++){
             for(int j=0; j<N; j++){
                if(B[i]==A[j]){
                    count+=5;
                }
           }
        }
        out << count << endl;
    }

return 0;
}


