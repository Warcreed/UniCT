#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include<iostream>

using namespace std;

template <class H> class MaxBinaryHeap{
	private:
		H **A;
		int heapsize;
		int len;
		int left(int i) { return i<<1; }
		int right(int i) { return (i<<1)|1; }
		int parent(int i) { return i>>1; }
		
		int compare(H* a, H* b){ return (*a)-(*b);}

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
		MaxBinaryHeap(H** a,int size) {
			A = a;
			len = size;
			heapsize = 0;
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
		bool** a = new bool*[N];
		
		for(int j=0; j<N; j++){
			cout << N << endl;
			in >> *a[j];
		}
			
		
		MaxBinaryHeap<bool> *H = new MaxBinaryHeap<bool>(a,N);
		H->BuildHeap();
		out << H->print() << endl;
		
	}
	
	if(type=="char"){
		char** a = new char*[N];
		for(int j=0; j<N; j++)
			in >> *a[j];
		
		MaxBinaryHeap<char> *H = new MaxBinaryHeap<char>(a,N);
		H->BuildHeap();
		out << H->print() << endl;
	}
	
	if(type=="int"){
		int** a = new int*[N];
		for(int j=0; j<N; j++)
			in >> *a[j];
		
		MaxBinaryHeap<int> *H = new MaxBinaryHeap<int>(a,N);
		H->BuildHeap();
		out << H->print() << endl;
	}
	
	if(type=="double"){
		double** a = new double*[N];
		for(int j=0; j<N; j++)
			in >> *a[j];
		
		MaxBinaryHeap<double> *H = new MaxBinaryHeap<double>(a,N);
		H->BuildHeap();
		out << H->print() << endl;
	}
}
return 0;
}
