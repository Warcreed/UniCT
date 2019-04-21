#include<fstream>
#include<sstream>
#include<string>

using namespace std;

class Terna{
    private:
        int* a;
        double* b;
        double* c;
    public:
        Terna(int a, double b, double c) : a(new int(a)), b(new double(b)), c(new double(c)){}
        
        int getA(){ return *a; }
        double getB(){ return *b; }
        double getC(){ return *c; }
};

int* counting(Terna** A, int N, int* len){
    int max = A[0]->getA();
    int min = A[0]->getA();
    for(int i = 0; i < N; i++){
        if(A[i]->getA() > max ) max = A[i]->getA();
        if(A[i]->getA() < min ) min = A[i]->getA();
    }
    *len = max - min + 1;
    int* C = new int[*len];
    for(int i = 0; i < *len; i++) C[i] = 0;
    for(int i = 0; i < N; i++) C[A[i]->getA()-min]++;
    for(int i = 1; i < *len; i++) C[i] += C[i-1];
    
    Terna* B[N] = {0};
    for(int i = N - 1; i >= 0; i--) B[(C[A[i]->getA() - min]--)-1] = A[i];

    for(int i = 0; i < N; i++) A[i] = B[i];

    return C;
}

string print(int* C, int N){
    stringstream s;
    for(int i = 0; i < N; i++)
        s << C[i] << " ";
    return s.str();
}

string print(Terna** A, int N){
    stringstream s;
    for(int i = 0; i < N; i++)
        s << "(" << ((double)A[i]->getA())/10 << " " << A[i]->getB() << " " << A[i]->getC() << ") ";
    return s.str();
}

int main(){
const int DIM = 100;
ifstream in("input.txt");
ofstream out("output.txt");
int N = 0;
for(int i = 0; i < DIM; i++){
    in >> N;
    Terna** A = new Terna*[N];
     for(int j = 0; j < N; j++){
        string a, b, c;
        stringstream s;
        double a1, b1, c1;
        in >> a >> b >> c;
        s << a.substr(1, a.length());
        s >> a1;
        s.clear();
        s << b;
        s >> b1;
        s.clear();
        s << c.substr(0, c.length()-1);
        s >> c1;
        A[j] = new Terna(a1 * 10 + 0.5, b1, c1);
     }
     int len;
     int* C = counting(A, N, &len);
     out << print(C, len) << print(A, N) << endl;
}
return 0;
}