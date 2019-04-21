/*  Si considera una tabella dove a partire dagli indici i = 1 e j = 1 corrispondono le lettere delle stringhe. Per ogni cella si considera la sottotruttura ottimale
    per cui si ha che se le due lettere sono uguali, allora non si applica nessuna delle tre operazioni (delete, insert, replace), si prende il valore in posizione i-1 e j-1
    nella tabella. Se le lettere sono diverse, si prende il minimo nella sottomatrice:
    replace insert
    delete  CELLA  
    e si aggiunge 1 azione da fare. Nella posizione table[N][M], ci sarà il numero minimo di operazioni per trasformare la strina a in b e viceversa.
*/
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int editLength(string a, string b, int N, int M){
    int** table = new int*[N+1];
    for(int i = 0; i <= N; i++){
        table[i] = new int[M+1];
        table[0][i] = i;
        table[i][0] = i;
    }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(a[i-1] == b[j-1]) table[i][j] = table[i-1][j-1];
            else table[i][j] = min({table[i][j-1], table[i-1][j-1], table[i-1][j]}) + 1;

    return table[N][M];
}

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0; int M = 0;
    string s1 = "", s2 = "";
    for(int i = 0; i < DIM; i++){
        in >> N >> M >> s1 >> s2;
        out << editLength(s1, s2, N, M) << endl;
    }
}