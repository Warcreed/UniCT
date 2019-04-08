#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

template <class H> class BinaryHeap
{
  private:
    H **A;
    int len;
    int heapsize;
    int left(int i) { return i << 1; }
    int right(int i) { return (i << 1) | 1; }
    int parent(int i) { return i >> 1; }

    void scambia(int a, int b)
    {
        H *temp = A[a];
        A[a] = A[b];
        A[b] = temp;
    }

    void heapify(int i){
        if(i>heapsize) return;
        int l = left(i);
        int r = right(i);
        int max = i;
        if(l<=heapsize && compare(A[max],A[l])) max = l;
        if(r<=heapsize && compare(A[max],A[r])) max = r; 
        if(max==i) return;
        scambia(i,max);
        heapify(max);
    }

    void checkParent(int i){
        while(i>1 && compare(A[parent(i)],A[i])){
            scambia(i, parent(i));
            i=parent(i);
        }
    }

  public:
    virtual bool compare(H* a, H* b) = 0;

    BinaryHeap(H** C, int size, int Nelement){
        A=C;
        len=size;
        heapsize=Nelement;
    }

    BinaryHeap(int size){
        A = new H*[size];
        len=size+1;
        heapsize=0;
    }

    void buildHeap(){
        for(int i=floor(heapsize/2); i>0; i--) heapify(i);
    }

    H* extractMax(){
        if(heapsize == 0) return NULL;
        scambia(1, heapsize);
        heapsize--;
        heapify(1);
        return A[heapsize+1];
    }

    void increaseKey(int i, H k){
        if(i>heapsize || i<1) return;
        *A[i]=k;
        checkParent(i);
    }

    BinaryHeap<H>* enqueue(H x){
        heapsize++;
        A[heapsize] = new H(x);
        checkParent(heapsize);
        return this;
    }

    int size(){ return heapsize;}

    string print() {
			stringstream tmp;
			for(int i=1; i<=heapsize; i++) 
				tmp << *A[i] << " ";
			return tmp.str();
		}
};

template<class H> class MinHeap : public BinaryHeap<H>{
  public:
    bool compare(H* a, H* b){ return (*b)<(*a);}
    MinHeap(int size) : BinaryHeap<H>(size){}
    MinHeap(H** A, int size, int Nelement) : BinaryHeap<H>(A,size,Nelement){}
};

int main(){
const int DIM = 100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    string type="";
    int N;
    in >> type >> N;

    if(type=="bool"){
        MinHeap<bool>* H = new MinHeap<bool>(N);
        for(int j=0; j<N; j++){
            bool tmp;
            in >> tmp;
            H->enqueue(tmp);
        }
        out << H->print() << endl;            
    }

    if(type=="int"){
        MinHeap<int>* H = new MinHeap<int>(N);
        for(int j=0; j<N; j++){
            int tmp;
            in >> tmp;
            H->enqueue(tmp);
        }
        out << H->print() << endl;               
    }

    if(type=="char"){
        MinHeap<char>* H = new MinHeap<char>(N);
        for(int j=0; j<N; j++){
            char tmp;
            in >> tmp;
            H->enqueue(tmp);
        }
        out << H->print() << endl;              
    }

    if(type=="double"){
        MinHeap<double>* H = new MinHeap<double>(N);
        for(int j=0; j<N; j++){
            double tmp;
            in >> tmp;
            H->enqueue(tmp);
        }
        out << H->print() << endl;            
    }
}
return 0;
}