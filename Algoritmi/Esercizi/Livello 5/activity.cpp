/*
    Viene considerata una tabella con numero di righe = all'ultimo tempo di fine e colonne = al numero di attività. L'algoritmo considera le righe come lo scorrere del tempo per le attività
    mentre le colonne come le attività stesse. Il passo consisten nel considerare la cella precedente se il tempo + minore del tempo di fine dell'attività analizzata correntemente, altrimenti 
    viene considerato il massimo trà la cella precedente a sinistra e la cella di riga corrispondente al tempo di inizio dell'attività precedente + la durata dell'attività corrente.
*/
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Activity{
    private:
        int* inizio;
        int* fine;
        int* durata;
    public:
        Activity(int i, int f) : inizio(new int(i)), fine(new int(f)), durata(new int(f-i)){}
        int getInizio(){ return *inizio; }
        int getFine(){ return *fine; }
        int getDurata(){ return *durata; }
};

void countingSort(Activity** A, int N){
    int max = A[0]->getFine();
    int min = A[0]->getFine();
    for(int i = 0; i < N; i++){
        if(A[i]->getFine() > max) max = A[i]->getFine();
        if(A[i]->getFine() < min) min = A[i]->getFine();
    }

    int len = max - min + 1;
    int C[len] = {0};
    for(int i = 0; i < N; i++) C[A[i]->getFine()-min]++;
    for(int i = 1; i < len; i++) C[i] += C[i-1];

    Activity** B = new Activity*[N];
    for(int i = N-1; i >= 0; i--) B[(C[A[i]->getFine()-min]--) - 1] = A[i];

     for(int i = 0; i < N; i++) A[i] = B[i];
}

 int maxActivity(Activity** A, int N){
    int len = A[N-1]->getFine()+1;
    int** table = new int*[len];
    for(int i = 0; i < len; i++){
        table[i] = new int[N+1];
        table[i][0] = 0;
    }
    for(int j = 0; j <= N; j++) table[0][j] = 0;
    
    for(int i = 1; i < len; i++){
        for(int j = 1; j <= N; j++){
            if(i<A[j-1]->getFine())
                table[i][j]=table[i][j-1];
            else
                table[i][j]=max(table[i][j-1],table[A[j-1]->getInizio()][j-1] + A[j-1]->getDurata());
        }
    }
    /* for(int k = 0; k <= N; k++){
        for(int l = 0; l <= N; l++){
            cout << table[k][l] << " ";
        }
    cout << endl;
    }
    cout << endl; */
    return table[len-1][N];
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
            int val1, val2;
            stringstream(s1.substr(1, s1.length())) >> val1;
            stringstream(s2.substr(0, s2.length()-1)) >> val2;
            A[j] = new Activity(val1, val2);  
        }
        countingSort(A, N);
        out << maxActivity(A, N) << endl;
        delete [] A;
    }
    in.close();
    out.close();
    return 0;
}