/*
    Usando un approccio greedy, si ordinano le attività rispetto al tempo di fine in maniera non decrescente, dopo di che si valuta la seconda (la prima si conta a priori),
    se il tempo di inizio della seconda è maggiore o coincide col tempo di fine di quella in corso, si conta l'attività e si pone la sia fine come nuova fine di confronto con le 
    successive.
*/
#include<fstream>
#include<sstream>

using namespace std;

class Activity{
    private:
        int inizio;
        int fine;
    public:
        Activity(int i, int f) : inizio(i), fine(f){}
        int getInizio(){ return inizio;}
        int getFine(){ return fine; }
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

int maxActivities(Activity** A, int N){
    countingSort(A, N);
    int count = 1, end = A[0]->getFine();
    for(int i = 1; i < N; i++){
        if(A[i]->getInizio() >= end){
            count++;
            end = A[i]->getFine();
        }
    }
    return count;
}

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0;
    for(int i = 0; i < DIM; i++){
        in >> N;
        Activity** V = new Activity*[N];
        for(int j = 0; j < N; j++){
            stringstream s;
            string tmp;
            in >> tmp;
            s << tmp.substr(1, tmp.length());
            int a1 = 0;
            s >> a1;
            s.clear();
            in >> tmp;
            s << tmp.substr(0, tmp.length()-1);
            int a2 = 0;
            s >> a2;
            V[j] = new Activity(a1, a2);
        }

        out << maxActivities(V, N) << endl;

        delete[] V;
    }
    in.close();
    out.close();
return 0;
}