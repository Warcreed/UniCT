#include<fstream>
#include<sstream>
#include<string>

using namespace std;

template<class H>
string print(H* A, int N){
    stringstream s;
    for(int i = 0; i < N; i++)
        s << A[i] << " ";
    return s.str();
}

int* counting(int* A, int N, int* K){
    int max = A[0];
    int min = A[0];
    for(int i = 1; i < N; i++){
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }

    *K = max - min + 1;
    int* C = new int[*K];
     for(int i = 0; i < *K; i++) C[i] = 0;
     for(int i = 0; i < N; i++) C[A[i]-min]++;
     for(int i = 1; i < *K; i++) C[i]+=C[i-1];
    
     int B[N] = {0};
     for(int i = N - 1; i>=0; i--) B[(C[A[i]-min]--) - 1] = A[i];

     for(int i = 0; i < N; i++) A[i] = B[i];
    return C;
}
 

int main(){
const int DIM = 100;
ifstream in("input.txt");
ofstream out("output.txt");
int N;
string type;
for(int i = 0; i < DIM; i++){
    in >> type >> N;
    if(type=="bool" || type=="int"){
        int A[N] = {0};
        for(int j = 0; j < N; j++) in >> A[j];
        int len;
        int* C = counting(A, N, &len);
        out << print(C, len) << print(A, N) << endl;
        delete C;
    }

    if(type=="char"){
        char A[N] = {0};
        int B[N] = {0};
        for(int j = 0; j < N; j++){
            in >> A[j];
            B[j] = (int) A[j];
        } 
        int len;
        int* C = counting(B, N, &len);
        for(int j = 0; j < N; j++) A[j] = (char) B[j]; 
        out << print(C, len) << print(A, N) << endl;
        delete C;
    }

    if(type=="double"){
        double A[N] = {0};
        int B[N] = {0};
        for(int j = 0; j < N; j++){
            in >> A[j];
            A[j]*=10;
            B[j] = A[j];
        } 
        int len;
        int* C = counting(B, N, &len);
        for(int j = 0; j < N; j++){
            A[j] = B[j];
            A[j]/=10;
        } 
        out << print(C, len) << print(A, N) << endl;
        delete C;
    }
}
return 0;
}