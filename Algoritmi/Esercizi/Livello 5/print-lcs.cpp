#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int** LCS(string X, string Y, int N, int M){
    int** C = new int*[N+1];
    for(int i = 0; i <= N; i++)  C[i] = new int[M+1];
    
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= M; j++){
            if(i == 0 || j == 0) C[i][j] = 0;
            else if(X[i-1] == Y[j-1]) C[i][j] = C[i-1][j-1]+1;
            else C[i][j] = max(C[i-1][j], C[i][j-1]);
        }
    return C;
}

//versione ricorsiva, si blocca per qualche motivo
void print_LCS(string X, string Y, int** C, int i, int j, ostream& out){
    if(i==0 || j==0) return;
    else if(X[i-1] == Y[j-1]){
        print_LCS(X, Y, C, i-1, j-1, out);
        out << X[i-1];
    }
    else if(C[i][j-1] >= C[i-1][j]) print_LCS(X, Y, C, i, j-1, out);
    else print_LCS(X, Y, C, i-1, j, out);

    delete [] C;
}

//versione iterativa funzionante
string print_LCS(string X, string Y, int** C, int i, int j){
   string s = "";
    while(i!=0 && j!=0){
        if(X[i-1] == Y[j-1]){
            s += X[i-1];
            i--;
            j--;
        }
        else if(C[i][j-1] >= C[i-1][j]) j--;
        else i--;
    }
    delete [] C;
    reverse(s.begin(), s.end()); //serve importare algotithm
    return s;
}

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0, M = 0;
    string s1 = "", s2 = "";
    for(int i = 0; i < DIM; i++){
        in >> N >> M >> s1 >> s2;
        out << print_LCS(s1, s2, LCS(s1, s2, N, M), N, M);
        out << endl;
    }
    return 0;
}