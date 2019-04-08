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
            A = new H**[++size];
            len = size;
            heapsize=0;
        }

        BinaryHeap(H** A, int size, int Nelement){
            this.A=A;
            len=size;
            heapsize=Nelement;
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
            scambia(1,heapsize--);
            heapify(1);
            return A[heapsize+1];
        }

        string print(){
            stringstream s = "";
            for(int i=1; i<=heapsize; i++)
                s << *A[i] << " ";
            return s.str();
        }

        int size(){ return heapsize;}
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

        in >> type;
        if(type.find(':')!=string::npos){
            stringstream s(type.substr(type.find(':')+1,type.length()));
            int v;
            s >> v;
            cout << ++v;
        }
            
        else
        {
            cout << "bonobo";
        }
        
    }
}

return 0;
}