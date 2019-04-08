#include<fstream>
#include<cmath>
#include<string>
#include<sstream>

using namespace std;

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
            A[i]=A[j];
            A[j]=tmp;
        }

        void heapify(int i){
            if(i<1 || i>heapsize) return;
            count++;
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
            scambia(parent(i),i);
            i = parent(i);
        }
    }
    public:
        virtual bool compare(H* a, H* b) = 0;

        BinaryHeap(int size){
            A = new H*[++size];
            len = size;
            heapsize=0;
            count=0;
        }

        BinaryHeap(H** A, int size, int Nelement){
            this.A=A;
            len = size;
            heapsize=Nelement;
            count=0;
        }

        void increaseKey(int i, H x){
            if(i<1 || i>heapsize) return;
            *A[i] = x;
            checkParent(i);
        }

        BinaryHeap<H>* enqueue(H x){
            heapsize++;
            A[heapsize] = new H(x);
            checkParent(heapsize);
            return this;
        }

        H* extractMax(){
            if(heapsize==0) return NULL;
            scambia(1,heapsize);
            heapsize--;
            heapify(1);
            return A[heapsize+1];
        }

        void buildHeap(){
            for(int i=floor(heapsize/2); i>0; i--) heapify(i);
        }

        int getCount(){ return count;}

        string print(){
            stringstream s;
            for(int i=1; i<=heapsize; i++)
                s << *A[i] << " ";
            return s.str();
        }
};

template<class H>
class MinHeap : public BinaryHeap<H>{
    public:
        bool compare(H* a, H* b){ return (*a)>(*b);}
        MinHeap(int size) : BinaryHeap<H>(size){}
        MinHeap(H** A, int size, int Nelement) : BinaryHeap<H>(A, size, Nelement){}
};

int main(){
const int DIM = 100;
ifstream in("input.txt");
ofstream out("output.txt");

int N;
string type;

for(int i=0; i<DIM; i++){
    in >> type >> N;

    if(type=="bool"){
        MinHeap<bool>* H = new MinHeap<bool>(N);
        for(int i=0; i<N; i++){
            in >> type;
            if(type[1]==':'){
                stringstream s(type.substr(2,type.length()));
                bool v;
                s >> v;
                H->enqueue(v);
            } else {
                H->extractMax();
            }
        }
        out << H->getCount() << " " << H->print() << endl;
    }

    if(type=="char"){
        MinHeap<char>* H = new MinHeap<char>(N);
        for(int i=0; i<N; i++){
            in >> type;
            if(type[1]==':'){
                H->enqueue(type[2]);
            } else {
                H->extractMax();
            }
        }
        out << H->getCount() << " " << H->print() << endl;
    }

    if(type=="int"){
        MinHeap<int>* H = new MinHeap<int>(N);
        for(int i=0; i<N; i++){
            in >> type;
            if(type[1]==':'){
                stringstream s(type.substr(2,type.length()));
                int v;
                s >> v;
                H->enqueue(v);
            } else {
                H->extractMax();
            }
        }
        out << H->getCount() << " " << H->print() << endl;
    }

    if(type=="double"){
        MinHeap<double>* H = new MinHeap<double>(N);
        for(int i=0; i<N; i++){
            in >> type;
            if(type[1]==':'){
                stringstream s(type.substr(2,type.length()));
                double v;
                s >> v;
                H->enqueue(v);
            } else {
                H->extractMax();
            }
        }
        out << H->getCount() << " " << H->print() << endl;
    }
}
return 0;
}