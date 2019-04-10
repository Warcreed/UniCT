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

        H** heapsort(){
            H** V = new H*[heapsize];
            buildHeap();

            for(int i = 1; i<len; i++)
               V[i-1] = new H(*extractMax());
            
            return V;
        } 
};

template<class H>
class MaxHeap : public BinaryHeap<H>{
    public:
        bool compare(H* a, H* b){ return (*a)>  (*b); }
        MaxHeap(H** A, int size, int Nelement) : BinaryHeap<H>(A, size, Nelement){}
};

int main(){
    const int DIM = 3;
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
            MaxHeap<bool>* H = new MaxHeap<bool>(V, N+1, N);
             V = H->heapsort();

             out << H->getCount() << " ";
            for(int j=0; j<N; j++)
                out << *V[j] << " ";
            out << endl;
            
        }

        if(type == "char"){
            char** V = new char*[N+1];
            for(int j=1; j<=N; j++){
                char tmp;
                in >> tmp;
                V[j] = new char(tmp);
            }
            MaxHeap<char>* H = new MaxHeap<char>(V, N+1, N);
             V = H->heapsort();

             out << H->getCount() << " ";
            for(int j=0; j<N; j++)
                out << *V[j] << " ";
            out << endl;
            
        }

        if(type == "int"){
            int** V = new int*[N+1];
            for(int j=1; j<=N; j++){
                int tmp;
                in >> tmp;
                V[j] = new int(tmp);
            }
            MaxHeap<int>* H = new MaxHeap<int>(V, N+1, N);
             V = H->heapsort();

             out << H->getCount() << " ";
            for(int j=0; j<N; j++)
                out << *V[j] << " ";
            out << endl;
            
        }

        if(type == "double"){
            double** V = new double*[N+1];
            for(int j=1; j<=N; j++){
                double tmp;
                in >> tmp;
                V[j] = new double(tmp);
            }
            MaxHeap<double>* H = new MaxHeap<double>(V, N+1, N);
             V = H->heapsort();

             out << H->getCount() << " ";
            for(int j=0; j<N; j++)
                out << *V[j] << " ";
            out << endl;       
        }    
    }
return 0;    
}
