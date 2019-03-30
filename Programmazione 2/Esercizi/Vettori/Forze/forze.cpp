#include<iostream>
#include<fstream>
#include<cmath>
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
            int i=0, j=0, k=0;
            while(i<N && j<M){
                if(A[i]<B[j]) C[k++]=A[i++];
                else C[k++] = B[j++];
            }
            while(i<N) C[k++] = A[i++];
            while(j<M) C[k++] = B[j++];


        for(int j=0; j<M+N; j++)
          out << C[j] << " ";

        out << endl;
    }

return 0;
}


