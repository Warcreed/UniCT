#include<fstream>
#include<sstream>
#include<string>
#include<cmath>

using namespace std;

template<class H>
class BinaryHeap{
    private:
        H** A;
        int heapsize;
        int count;
        int left(int i){ return i<<1; }
        int right(int i){ return (i<<1)|1; }
        int parent(int i){ return i>>1; }

        void scambia(int i, int j){
            H* tmp = A[i];
            A[i]=A[j];
            A[j]=tmp;
        }

        void heapify(int i){
            if(i<0 || i>heapsize) return;
            count++;
            int l = left(i);
            int r = right(i);
            int max = i;
            if(l<=heapsize && compare(A[max], A[l])) max = l;
            if(r<=heapsize && compare(A[max], A[r])) max = r;
            if(max==i) return;
            scambia(i,max);
            heapify(max);
        }

    public:
        virtual bool compare(H* a, H* b) = 0;

        BinaryHeap(H** C, int hpsize){
            A = C;
            heapsize = hpsize;
            count = 0;
        }

        void buildHeap(){
            for(int i=floor(heapsize/2); i>0; i--) heapify(i);
        }

        H* extractMax(){
            if(heapsize == 0) return NULL;
            scambia(1,heapsize--);
            heapify(1);
            return A[heapsize+1];
        }

        int getCount(){ return count;}
};

template<class H>
class MaxHeap : public BinaryHeap<H>{
    public:
        bool compare(H* a, H* b){ return (*a)<(*b);}
        MaxHeap(H** A, int size) : BinaryHeap<H>(A, size){}
};

int main(){
const int DIM = 100;
ifstream in("input.txt");
ofstream out("output.txt");

string type = "";
int N = 0;

for(int i=0; i<DIM; i++){
    in >> type >> N;

    if(type=="bool"){
        bool** v = new bool*[N+1];
        for(int j=1; j<=N; j++){
            bool tmp;
            in >> tmp;
            v[j]= new bool(tmp);
        }
        MaxHeap<bool>* H = new MaxHeap<bool>(v,N);
        H->buildHeap();
        for(int j=0; j<N; j++)
            H->extractMax();
        
        out << H->getCount() << endl;
    }

    if(type=="int"){
        int** v = new int*[N+1];
        for(int j=1; j<=N; j++){
            int tmp;
            in >> tmp;
             v[j]= new int(tmp);
        }
        MaxHeap<int>* H = new MaxHeap<int>(v,N);
        H->buildHeap();
        for(int j=0; j<N; j++)
            H->extractMax();
        
        out << H->getCount() << endl;
    }

    if(type=="char"){
        char** v = new char*[N+1];
        for(int j=1; j<=N; j++){
            char tmp;
            in >> tmp;
             v[j]= new char(tmp);
        }
        MaxHeap<char>* H = new MaxHeap<char>(v,N);
        H->buildHeap();
        for(int j=0; j<N; j++)
            H->extractMax();
        
        out << H->getCount() << endl;
    }

    if(type=="double"){
        double** v = new double*[N+1];
        for(int j=1; j<=N; j++){
            double tmp;
            in >> tmp;
             v[j]= new double(tmp);
        }
        MaxHeap<double>* H = new MaxHeap<double>(v,N);
        H->buildHeap();
        for(int j=0; j<N; j++)
            H->extractMax();
        
        out << H->getCount() << endl;
    }
}
return 0;
}