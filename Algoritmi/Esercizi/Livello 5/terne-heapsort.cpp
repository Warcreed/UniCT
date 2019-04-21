#include<fstream>
#include<sstream>
#include<cmath>
#include<string>

using namespace std;

template<class H>
class Terna{
    private:
        H* a;
        H* b;
        H* c;
    public:
        Terna(H a, H b, H c): a(new H(a)), b(new H(b)), c(new H(c)){}

        H getA(){return *a;}
        H getB(){return *b;}
        H getC(){return *c;}
};

template<class H>
class BinaryHeap{
    private:
        H** A;
        int len;
        int heapsize;
        int count;
        int left(int i){ return i<<1; }
        int right(int i){ return (i<<1)|1; }
        int parent(int i){ return i>>1; }

        void scambia(int i, int j){
            H* tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }

        void heapify(int i){
            if(i < 0 || i > heapsize) return;
            count++;
            int l = left(i);
            int r = right(i);
            int max = i;
            if(l <= heapsize && compare(A[max], A[l])) max = l;
            if(r <= heapsize && compare(A[max], A[r])) max = r;
            if(max == i) return;
            scambia(max, i);
            heapify(max);

        }
    public:
        virtual bool compare(H* a, H* b) = 0;

        BinaryHeap(H** C, int size, int Nelement){
            A = C;
            len = size;
            heapsize = Nelement;
            count = 0;
        }

        void buildHeap(){
            for(int i = floor(heapsize/2); i>0; i--) heapify(i);
        }

        H* extractMax(){
            if(heapsize == 0) return nullptr;
            scambia(1, heapsize--);
            heapify(1);
            return A[heapsize+1];
        }

        void heapsort(){
            buildHeap();
            for(int i=1; i<len; i++)
                extractMax();
        }

        int getCount(){ return count; }

        string print(){
            stringstream s;
            for(int i=1; i<len; i++)
                s << "(" << A[i]->getA() << " " << A[i]->getB() << " " << A[i]->getC() << ") ";
            return s.str();
        }
};

template<class H>
class MaxHeap : public BinaryHeap<H>{
    public:
        MaxHeap(H** A, int size, int Nelement) : BinaryHeap<H>(A, size, Nelement){}
        
        bool compare(H* a, H* b){
            if(a->getA() < b->getA() || (a->getA() == b->getA() && (a->getB() < b->getB())) || (a->getA() == b->getA() && a->getB() == b->getB() && (a->getC() < b->getC()))))
                return true;
            return false;
        }
};
int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N = 0;
    string type = "";

    for(int i = 0; i < DIM; i++){
        in >> type >> N;

        if(type == "bool"){
            Terna<bool>** v = new Terna<bool>*[N+1];
            for(int j = 1; j<=N; j++){
                string a, b, c;
                stringstream s1, s2, s3;
                in >> a >> b >> c;
                s1 << a.substr(1,a.length());
                s2 << b;
                s3 << c.substr(0,c.length()-1);
                bool a1, a2, a3;
                s1 >> a1;
                s2 >> a2;
                s3 >> a3;
                v[j] = new Terna<bool>(a1, a2, a3);
           }

           MaxHeap<Terna<bool>>* H = new MaxHeap<Terna<bool>>(v, N+1, N);
           H->heapsort();

           out << H->getCount() << " " << H->print() << endl;         
        }

        if(type == "char"){
            Terna<char>** v = new Terna<char>*[N+1];
            for(int j = 1; j<=N; j++){
                string a, b, c;
                in >> a >> b >> c;
                v[j] = new Terna<char>(a[1], b[0], c[0]);
           }

           MaxHeap<Terna<char>>* H = new MaxHeap<Terna<char>>(v, N+1, N);
           H->heapsort();

           out << H->getCount() << " " << H->print() << endl;         
        }

        if(type == "int"){
            Terna<int>** v = new Terna<int>*[N+1];
            for(int j = 1; j<=N; j++){
                string a, b, c;
                stringstream s1, s2, s3;
                in >> a >> b >> c;
                s1 << a.substr(1,a.length());
                s2 << b;
                s3 << c.substr(0,c.length()-1);
                int a1, a2, a3;
                s1 >> a1;
                s2 >> a2;
                s3 >> a3;
                v[j] = new Terna<int>(a1, a2, a3);
           }

           MaxHeap<Terna<int>>* H = new MaxHeap<Terna<int>>(v, N+1, N);
           H->heapsort();

           out << H->getCount() << " " << H->print() << endl;         
        }

        if(type == "double"){
            Terna<double>** v = new Terna<double>*[N+1];
            for(int j = 1; j<=N; j++){
                string a, b, c;
                stringstream s1, s2, s3;
                in >> a >> b >> c;
                s1 << a.substr(1,a.length());
                s2 << b;
                s3 << c.substr(0,c.length()-1);
                double a1, a2, a3;
                s1 >> a1;
                s2 >> a2;
                s3 >> a3;
                v[j] = new Terna<double>(a1, a2, a3);
           }

           MaxHeap<Terna<double>>* H = new MaxHeap<Terna<double>>(v, N+1, N);
           H->heapsort();

           out << H->getCount() << " " << H->print() << endl;         
        }
    }
    return 0;
}