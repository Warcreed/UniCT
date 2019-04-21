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

int** numCoins(int* A, int N, int R){
    int** restTable = new int*[N+1];
    for(int i = 0; i <= N; i++){
         restTable[i] = new int[R+1];
        restTable[i][0] = 0;
    }
    for(int i = 0; i <= R; i++) restTable[0][i] = INT_MAX-1;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= R; j++)
            if(A[i-1] > j) restTable[i][j] = restTable[i-1][j];
            else restTable[i][j] = min(restTable[i][j - A[i-1]] + 1, restTable[i-1][j]);
            
     /* for(int i = 1; i <= N; i++){
        for(int j = 0; j <= R; j++)
            cout << restTable[i][j] << " ";
        cout << endl; 
    }   */

    return restTable;
}
 void printResto(int** rest, int i, int j, int* A, ostream& out){
 	
     if(j <= 0) return;
     if(rest[i][j] != rest[i-1][j]){
         printResto(rest, i, j - A[i-1], A, out);
         out <<  A[i-1] << " ";
         
     }
     else{
          printResto(rest, i - 1 , j, A, out); 
         //cout << i << " " <<  j << " " << endl;
     } 
     
    /*  string s = "";
     while(j != 0){
         if(rest[i][j] != rest[i-1][j]){
             s += (char) A[i] + ' ';
             j -= A[i]; 
         }
         else i--;
         cout << s << " ";
    }
    return s; */
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
        int** rest = numCoins(A, N, R);        
        string s = "";
        out << rest[N][R] << " "; 
        printResto(rest, N, R, A, out);
        out << endl;
    }
    return 0;
}
