/*
    Si tratta semplicemente di ordinare rispetto al valore più grande e andarlo ad inserire nello zaino sottrendo 1 posto (peso unitario). Si resituisce la somma dei valori.
*/
#include<fstream>

using namespace std;

void countingSort(int* V, int N){
    int max = V[0];
    int min = V[0];
    for(int i = 0; i < N; i++){
        if(V[i] > max) max = V[i];
        if(V[i] < min) min = V[i];
    }

    int len = max - min + 1;
    int C[len] = {0};
    for(int i = 0; i < N; i++) C[V[i] - min]++;
    for(int i = 1; i <= len; i++) C[i] += C[i-1];

    int B[N] = {0};
    for(int i = N-1; i >= 0; i--) B[(C[V[i] - min]--) - 1] = V[i];

    for(int i = 0; i < N; i++) V[i] = B[N-i-1];
}

int maxValue(int* V, int N, int P){
    int value = 0, i = 0;
    while(P>0){
        value += V[i++];
        P--;
    } 
    return value;
}

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0, PESO = 0;
    for(int i = 0; i < DIM; i++){
        in >> N >> PESO;
        int V[N] = {0};
        for(int j = 0; j < N; j++) in >> V[j]; 
        countingSort(V, N);
        out << maxValue(V, N, PESO) << endl;
    }
        return 0;
}