#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Activity{
    private:
        int* inizio;
        int* fine;
    public:
        Activity(int i, int f) : inizio(new int(i)), fine(new int(f)){}
        int getInizio(){ return *inizio; }
        int getFine(){ return *fine; }
};

bool compatible(Activity* a, Activity* b){
    return ((b->getInizio() <= a->getInizio() || b->getInizio() >= a->getFine()) && 
            (b->getFine() <= a->getInizio() || b->getFine() >= a->getFine()));
}

 int maxActivity(Activity** A, int N){
    int** table = new int*[N+1];
    for(int i = 0; i <= N; i++){
        table[i] = new int[N+1];
        table[0][i] = table[i][0] = 1;
    }

    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            
            if(A[i-1]->getInizio() == A[j-1]->getInizio() && A[i-1]->getFine() == A[j-1]->getFine())
                table[i][j] = table[i][j-1];
            else if(compatible(A[i-1], A[j-1])) table[i][j] = table[i][j-1] + 1;
            else table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }
    /* for(int k = 0; k <= N; k++){
        for(int l = 0; l <= N; l++){
            cout << table[k][l] << " ";
        }
    cout << endl;
    }
    cout << endl; */
    

    return table[N][N];
} 
int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0;
    for(int i = 0; i < DIM; i++){
        in >> N;
        Activity** A = new Activity*[N];
        for(int j = 0; j < N; j++){
            string s1, s2;
            in >> s1 >> s2;
            stringstream s;
            s << s1.substr(1, s1.length());
            int val1;
            s >> val1;
            s.clear();
            s << s2.substr(0, s1.length()-1);
            int val2;
            s >> val2;
            A[j] = new Activity(val1, val2);  
        }
        out << maxActivity(A, N) <<endl;
        delete [] A;
    }
    in.close();
    out.close();
    return 0;
}