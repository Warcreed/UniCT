#include<fstream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

template <class T> class PriorityQueue {
	public:
		virtual T* extractMax() = 0;
		virtual PriorityQueue<T>* enqueue(T x) = 0;
		virtual int size() = 0;
};

template <class H> class BinaryHeap : public PriorityQueue<H>{
	private:
		H **A;
		int heapsize;
		int len;
		int left(int i) { return i<<1; }
		int right(int i) { return (i<<1)|1; }
		int parent(int i) { return i>>1; }
		
		void scambia(int i, int j) {
			H* tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
		
		void heapify(int i) {
			if(i>heapsize) return;
			int l = left(i);
			int r = right(i);
			int max = i;
			if(l<=heapsize && compare(A[max], A[l])<0) max=l;
			if(r<=heapsize && compare(A[max], A[r])<0) max=r;
			if(max==i) return;
			scambia(i,max);
			heapify(max);
		}
		
		
	public:
		virtual int compare(H *a, H *b)=0;
		BinaryHeap(int size) {
			A = new H*[size];
			len = size;
			heapsize = 0;
		}
		
		H* extractMax() {
			if(heapsize==0) return NULL;
			scambia(1, heapsize);
			heapsize--;
			heapify(1);
			return A[heapsize+1];
		}
		
		BinaryHeap<H>* enqueue(H x) {
			heapsize += 1;
			A[heapsize] = new H(x);
			int i = heapsize;
			while(i>1 && compare(A[i],A[parent(i)])>0) {
				scambia(i, parent(i));
				i = parent(i);
			}
			return this;
		}
		
		BinaryHeap<H>* increaseKey(int i, H *k) {
			if(i>heapsize) return this;
			if(i<1) return this;
			if( *A[i] >= *k ) return this;
			*A[i] = *k;
			while(i>1 && compare(A[i],A[parent(i)])>0) {
				scambia(i, parent(i));
				i = parent(i);
			}
			return this;
		}
		
		int size() {
			return heapsize;
		}
		
		string print() {
			stringstream tmp;
			for(int i=1; i<=heapsize; i++) 
				tmp << *A[i] << " ";
			return tmp.str();
		}
		
		void BuildHeap(){
			for(int i=floor(heapsize/2); i>0; i--) heapify(i);
		}
};

template <class H> class MaxBinaryHeap : public BinaryHeap<H> {
	private: 
	public:
		int compare(H* a, H *b) {
			return (*a)-(*b);
		}
		MaxBinaryHeap(int size) : BinaryHeap<H>(size) {}
};


int main(){

const int DIM=3;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
	string type="";
	in >> type;
	int N=0;
	in >> N;
	if(type=="bool"){
		MaxBinaryHeap<bool> *H = new MaxBinaryHeap<bool>(100);
		for(int j=0; j<N; j++){
			bool tmp;
			in >> tmp;
			H->enqueue(tmp);
		}
		H->BuildHeap();
		out << H->print() << endl;
	}
	
	if(type=="int"){
		MaxBinaryHeap<int> *H = new MaxBinaryHeap<int>(100);
		for(int j=0; j<N; j++){
			int tmp;
			in >> tmp;
			H->enqueue(tmp);
		}
		H->BuildHeap();
		out << H->print() << endl;
	}
	
	if(type=="char"){
		MaxBinaryHeap<char> *H = new MaxBinaryHeap<char>(100);
		for(int j=0; j<N; j++){
			char tmp;
			in >> tmp;
			H->enqueue(tmp);
		}
		H->BuildHeap();
		out << H->print() << endl;
	}
	
	if(type=="double"){
		MaxBinaryHeap<double> *H = new MaxBinaryHeap<double>(100);
		for(int j=0; j<N; j++){
			double tmp;
			in >> tmp;
			H->enqueue(tmp);
		}
		H->BuildHeap();
		out << H->print() << endl;
	}	
}
return 0;
}
