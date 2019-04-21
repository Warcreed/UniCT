#include<fstream>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<climits>

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

int numCoins(int* A, int N, int R, int* coins){
    int* restTable = new int[R+1];
    restTable[0] = 0;
    for(int i = 1; i <= R; i++) restTable[i] = INT_MAX-1;           //-1 importante perché altrimenti INT_MAX ruota al valore negativo
                                                                    //nel caso in cui considero il minimo di una cella che non è stata modificata precedentemente.
    for(int i = 1; i <= R; i++){ 
        int coin = -1;                                   
         for(int j = 0; j < N; j++){
             if(i >= A[j]){
                int tmp = restTable[i];
                restTable[i] = min(restTable[i - A[j]] + 1, restTable[i]);
                if(restTable[i] != tmp) coins[i] = A[j]; 
             }     
         }
    }    
    return restTable[R];
}

string printCoins(int* coins, int R){
    int i = R;
    stringstream s;
    int usedCoins[R];
    int j = 0;
    while(i > 0){
        usedCoins[j++] = coins[i];
        i -= coins[i];
    }
    countingSort(usedCoins, j);
    for(int i = 0; i < j; i++) s << usedCoins[i] << " ";
    string out = s.str();
    return out;
}

/* Metodo ricorsivo, non perfettamente funzionante
void printResto(int** rest, int i, int j, int* A, ostream& out){
 	
     if(j <= 0) return;
     if(rest[i][j] != rest[i-1][j]){
         printResto(rest, i, j - A[i-1], A, out);
         out <<  A[i-1] << " ";   
     }
     else printResto(rest, i - 1 , j, A, out); 
         //cout << i << " " <<  j << " " << endl;
      string s = "";
     while(j != 0){
         if(rest[i][j] != rest[i-1][j]){
             s += (char) A[i] + ' ';
             j -= A[i]; 
         }
         else i--;
         cout << s << " ";
    }
    return s; 
 } */

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int R = 0, N = 0;
    for(int i = 0; i < DIM; i++){
        in >> R >> N;
        int A[N] = {0};
        for(int j = 0; j < N; j++) in >> A[j];
        int coins[R+1];
        int rest = numCoins(A, N, R, coins);        
        out << rest << " " << printCoins(coins, R) << endl;
    }
    return 0;
}
