#include<fstream>
#include<sstream>
#include<string>

using namespace std;

class Coppia{
    private:
        int* a;
        int* b;
    public:
        Coppia(int a, int b): a(new int(a)), b(new int(b)){}
        int getA(){return *a;}
        int getB(){return *b;}
};

int* counting(Coppia** A, int N, int* len){
    
    int max = A[0]->getA();
    int min = A[0]->getA();
    
    for(int i = 0; i < N; i++){
        if(A[i]->getA() > max) max = A[i]->getA();
        if(A[i]->getA() < min) min = A[i]->getA();
    }

    *len = max - min + 1;
    int* C = new int[*len];
    for(int i = 0; i < *len; i++) C[i] = 0;  
    for(int i = 0; i < N; i++) C[A[i]->getA() - min]++;
    for(int i = 1; i < *len; i++) C[i] += C[i-1];
    
    Coppia* B[N] = {0};
    for(int i = N-1; i >= 0; i--) B[(C[A[i]->getA() - min]--) - 1] = A[i];
    for(int i = 0; i < N; i++) A[i] = B[i];
    return C;
}

string print(Coppia** A, int N){
    stringstream s;
    for(int i = 0; i < N; i++)
        s << "(" << ((double)A[i]->getA())/10 << " " << ((double)A[i]->getB())/10 << ") ";
    return s.str();
}

string print(int* A, int N){
    stringstream s;
    for(int i = 0; i < N; i++)
        s << A[i] << " ";
    return s.str();
}

int main(){
const int DIM = 100;
ifstream in("input.txt");
ofstream out("output.txt");
int N = 0;

for(int i = 0; i < DIM; i++){
    in >> N;
    Coppia** A = new Coppia*[N];
    for(int j = 0; j < N; j++){
        string a, b;
        stringstream s1, s2;
        in >> a >> b;
        s1 << a.substr(1,a.length()-1);
        s2 << b.substr(0,b.length()-1);
        double a1, b1;
        s1 >> a1;
        s2 >> b1;
        A[j] = new Coppia(a1 * 10 + 0.5, b1 * 10 + 0.5);
    }
    int len;
    int* C = counting(A, N, &len);
    out << print(C, len) << print(A, N) << endl;
}
return 0;
}