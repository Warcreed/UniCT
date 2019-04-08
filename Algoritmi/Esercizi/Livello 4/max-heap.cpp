#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

template<class H> class BinaryHeap{
    private:
        H** A;
        int len;
        int heapsize;
        int count;
        int left(int i){ return i<<1;}
        int right(int i){ return (i<<1)|1;}
        int parent(int i){ return i>>1;}

        void scambia(int a, int b){
            H* tmp = A[a];
            A[a]=A[b];
            A[b]=tmp;
        }

        void heapify(int i){
            if(i>heapsize) return;
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
            A = new H*[size];
            len = size+1;
            heapsize=0;
            count = 0;
        }

        BinaryHeap(H** A, int size, int Nelement){
            this.A=A;
            len=size;
            heapsize=Nelement;
            count = 0;
        }

        void BuildHeap(){
            for(int i=floor(heapsize/2); i>0; i--) heapify(i);
        }

        BinaryHeap<H>* enqueue(H x){
            heapsize++;
            A[heapsize] = new H(x);
            checkParent(heapsize);
            return this;
        }

        void increaseKey(int i, H k){
            if(i>heapsize || i<1) return;
            *A[i]=k;
            checkParent(i);
        }

        H* extractMax(){
            if(heapsize==0) return NULL;
            scambia(1,heapsize);
            heapsize--;
            heapify(1);
            return A[heapsize+1];
        }

        string print(){
            stringstream s;
            for(int i=1; i<=heapsize; i++)
                s << *A[i] << " ";
            return s.str();
        }

        int getCount(){ return count;}
};

template<class H> class MaxHeap : public BinaryHeap<H>{
    public:
        MaxHeap(int size) : BinaryHeap<H>(size){}
        MaxHeap(H** A, int size, int N) : BinaryHeap<H>(A,size, N){}

        bool compare(H* a, H* b){ return (*a) < (*b);}
};

int main(){

const int DIM = 3;
ifstream in("input.txt");
ofstream out("output.txt");

string type = "";
int N = 0;

for(int i=0; i<DIM; i++){
    in >> type >> N;

    if(type=="bool"){
        MaxHeap<bool>* H = new MaxHeap<bool>(N);
        for(int j=0; j<N; j++){
            in >> type;
            if(type[1]==':'){
                stringstream s(type.substr(2,type.length()));
                bool v;
                s >> v;
                H->enqueue(v);
            }
            else{
                H->extractMax();
            }
            //cout << type << " heap: " << H->print() << endl;
        }
        out << H->getCount() << " " << H->print() << endl;
    }

    if(type=="char"){
        MaxHeap<char>* H = new MaxHeap<char>(N);
        for(int j=0; j<N; j++){
            in >> type;
            if(type[1]==':'){
                H->enqueue(type[2]);
            }
            else{
                H->extractMax();
            }
        }
        out << H->getCount() << " " << H->print() << endl;
    }

    if(type=="int"){
        MaxHeap<int>* H = new MaxHeap<int>(N);
        for(int j=0; j<N; j++){
            in >> type;
            if(type[1]==':'){
                stringstream s(type.substr(2,type.length()));
                int v;
                s >> v;
                H->enqueue(v);
            }
            else{
                H->extractMax();
            }
        }
        out << H->getCount() << " " << H->print() << endl;
    }

    if(type=="double"){
        MaxHeap<double>* H = new MaxHeap<double>(N);
        for(int j=0; j<N; j++){
            in >> type;
            if(type[1]==':'){
                stringstream s(type.substr(2,type.length()));
                double v;
                s >> v;
                H->enqueue(v);
            }
            else{
                H->extractMax();
            }
        }
        out << H->getCount() << " " << H->print() << endl;
    }
}

return 0;
}
