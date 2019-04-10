#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<iostream>

using namespace std;

template<class H>
class BinaryHeap{
    private:
        H** A;
        int heapsize;
        int len;
        int count;
        int left(int i){ return i<<1; }
        int right(int i){ return (i<<1)|1; }
        int parent(int i){ return i>>1; }

        void swap(int i, int j){
            H* tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }

        void heapify(int i){
            if(i<1 || i>heapsize) return;
            count++;
            int l = left(i);
            int r = right(i);
            int max = i;
            if(l<=heapsize && compare(A[max], A[l])) max = l;
            if(r<=heapsize && compare(A[max], A[r])) max = r;
            if(max==i) return;
            swap(i, max);
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
            if(heapsize == 0) return NULL;
            swap(1, heapsize--);
            heapify(1);
            return A[heapsize+1];
        }

        int getCount(){ return count;}

        void heapsort(){
            buildHeap();

            for(int i = 1; i<len; i++)
               extractMax();
        } 

        string print(){
            stringstream s("ciao");
            for(int i = 1; i<len; i++)
                s << *A[i] << " ";
            return s.str();
        }
};

template<class H>
class MinHeap : public BinaryHeap<H>{
    public:
        bool compare(H* a, H* b){ return (*a) > (*b); }
        MinHeap(H** A, int size, int Nelement) : BinaryHeap<H>(A, size, Nelement){}
};

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0;
    string type = "";

    for(int i = 0; i<DIM; i++){
        in >> type >> N;

        if(type == "bool"){
            bool** V = new bool*[N+1];
            for(int j=1; j<=N; j++){
                bool tmp;
                in >> tmp;
                V[j] = new bool(tmp);
            }
            MinHeap<bool>* H = new MinHeap<bool>(V, N+1, N);
            H->heapsort();

            out << H->getCount() << " " << H->print() << endl;      
        }

        if(type == "char"){
            char** V = new char*[N+1];
            for(int j=1; j<=N; j++){
                char tmp;
                in >> tmp;
                V[j] = new char(tmp);
            }
            MinHeap<char>* H = new MinHeap<char>(V, N+1, N);
            H->heapsort();

            out << H->getCount() << " " << H->print() << endl;
        }

        if(type == "int"){
            int** V = new int*[N+1];
            for(int j=1; j<=N; j++){
                int tmp;
                in >> tmp;
                V[j] = new int(tmp);
            }
            MinHeap<int>* H = new MinHeap<int>(V, N+1, N);
             H->heapsort();

            out << H->getCount() << " " << H->print() << endl;
        }

        if(type == "double"){
            double** V = new double*[N+1];
            for(int j=1; j<=N; j++){
                double tmp;
                in >> tmp;
                V[j] = new double(tmp);
            }
            MinHeap<double>* H = new MinHeap<double>(V, N+1, N);
             H->heapsort();

            out << H->getCount() << " " << H->print() << endl;
        }    
    }
return 0;    
}