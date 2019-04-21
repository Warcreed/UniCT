 /*
    Approccio bottom-up. Si considera un vettore i cui indici corrispondono ai resti (da 1 fino ad R), nella posizione 0 si aggiunge 0 di default.
    Per ogni cella si ruotano tutte le monete, se la differenza tra il resto e la moneta non è negativa (i >= A[j]) si considera il minimo tra il valore
    già presente nella cella (possibile sottocaso ottimo, bisogna inizializzare da 1 a R con INT_MAX-1) e il valore presente nella posizione i - ValMoneta (A[j]).
    Esso è gia considerabile come una sottostruttura ottimale, al quale bisogna aggiungere 1, che corrisponde all'uso della moneta corrente. Si itera per tutto l'array dei resti.
    Nell'ultima cella si troverà il numero minimo di monete.
*/
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

void countingSort(int* A, int N){
    int max = A[0];
    int min = A[0];
    for(int i = 0; i < N; i++){
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }
    int len = max - min + 1;
    int C[len] = {0};
    for(int i = 0; i < N; i++) C[A[i] - min]++;
    for(int i = 1; i < len; i++) C[i] += C[i-1];

    int B[N] = {0};
    for(int i = N-1; i >= 0; i--) B[(C[A[i]-min]--) - 1] = A[i];

    for(int i = 0; i < N; i++) A[i] = B[i];
}

int numMoneteResto(int* A, int N, int R){
    int* restTable = new int[R+1];
    restTable[0] = 0;
    for(int i = 1; i <= R; i++) restTable[i] = INT_MAX-1;           //-1 importante perché altrimenti INT_MAX ruota al valore negativo
                                                                    //nel caso in cui considero il minimo di una cella che non è stata modificata precedentemente.
    for(int i = 1; i <= R; i++){                                    
         for(int j = 0; j < N; j++){
             if(i >= A[j])
                restTable[i] = min(restTable[i - A[j]] + 1, restTable[i]); 
         }
    }    
    return restTable[R];
}

//versione con matrice, da preferire se bisogna calcolare l'insieme delle monete print-resto
int numMoneteRestoMatrix(int* A, int N, int R){
    int** restTable = new int*[N+1];
    for(int i = 0; i <= N; i++) restTable[i] = new int[R+1];          
    for(int i = 0; i <= N; i++) restTable[i][0] = 0;
    for(int i = 0; i <= R; i++) restTable[0][i] = INT_MAX-1;        //-1 importante perché altrimenti INT_MAX ruota al valore negativo
                                                           
    for(int i = 1; i <= N; i++){                                    
         for(int j = 1; j <= R; j++){
             if(A[i-1] > j) restTable[i][j] = restTable[i-1][j];
             else  restTable[i][j] = min(restTable[i][j - A[i-1]] + 1, restTable[i-1][j]); 
         }
    }
    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= R; j++)
    //         cout << restTable[i][j] << " ";
    // cout << endl;
    // }                            
         
    return restTable[N][R];
}

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int R = 0, N = 0;
     for(int i = 0; i < DIM; i++){
         in >> R >> N;
         int A[N] = {0};
         for(int j = 0; j < N; j++) in >> A[j];
         countingSort(A, N);
         out << numMoneteRestoMatrix(A, N, R) << endl;
     }
    return 0;
}
