#include<fstream>
#include<sstream>
#include<cmath>
#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

template<class H>
class Coppia{
    public:
        H* a;
        H* b;

        Coppia(H a, H b): a(new H(a)), b(new H(b)){}
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

        BinaryHeap(H** A, int size, int Nelement){
            this.A = A;
            len = size;
            heapsize = Nelement;
            count = 0;
        }

        void buildHeap(){
            for(int i = floor(heapsize/2); i>0; i--) heapify(i);
        }

        H* extractMax(){
            if(heapsize == 0) return nullptr;
            scambia(1, heapsize);
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
                s << *A[i] << " ";
            return s.str();
        }
};

int main(){
    const int DIM = 1;
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N = 0;
    string type = "";

    for(int i = 0; i < DIM; i++){
        in >> type >> N;

        if(type == "bool"){
            Coppia<bool>** v = new Coppia<bool>*[N+1];
            for(int j = 1; j<=N; j++){
                string a, b;
                stringstream s1, s2;
                in >> a >> b;
                s1 << a.substr(1,a.length());
                s2 << b.substr(1,b.length()-1);
                bool a1, a2;
                s1 >> a1;
                s2 >> a2;
                v[j] = new Coppia<bool>(a1, a2);
                cout << *(v[j]->a) << " " << v[j]->b << endl;
           }
            

        }
    }
    return 0;
}
