#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    const int DIM=100;
for(int i=0; i<DIM; i++){
    int N=0, M=0;
    in >> N >> M;
    int A[N][M];
    for(int j=0; j<N; j++){
            for(int k=0; k<M; k++)
                in >> A[j][k];
    }
    int B[N][M];
    for(int j=0; j<N; j++){
            for(int k=0; k<M; k++)
                in >> B[j][k];
    }
    for(int j=0; j<N; j++){
            for(int k=0; k<M; k++)
                out << A[j][k]+B[j][k] << " ";
    }
    out << endl;
}
return 0;
}
