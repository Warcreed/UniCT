#include<fstream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

template <class H> class MaxBinaryHeap{
	private:
		H **A;
		int heapsize;
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
			if(l<=heapsize && *A[l]>*A[i]) max=l;
			if(r<=heapsize && *A[r]>*A[max]) max=r;
			if(max==i) return;
			scambia(i,max);
			heapify(max);
		}
		
		
	public:
		MaxBinaryHeap(H** a,int size) {
			A = a;
			heapsize = size;
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

const int DIM=100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
	string type="";
	in >> type;
	int N=0;
	in >> N;
	if(type=="bool"){
		bool** a = new bool*[N+1];
		for(int j=1; j<=N; j++){
			a[j]= new bool;
			in >> *a[j];
		}
			
		MaxBinaryHeap<bool> *H = new MaxBinaryHeap<bool>(a,N);
		H->BuildHeap();
		out << H->print() << endl;
		
	}
	
	if(type=="char"){
		char** a = new char*[N+1];
		for(int j=1; j<=N; j++){
			a[j]= new char;
			in >> *a[j];
		}
		
		MaxBinaryHeap<char> *H = new MaxBinaryHeap<char>(a,N);
		H->BuildHeap();
		out << H->print() << endl;
	}
	
	if(type=="int"){
		int** a = new int*[N+1];
		for(int j=1; j<=N; j++){
			a[j]= new int;
			in >> *a[j];
		}
		
		MaxBinaryHeap<int> *H = new MaxBinaryHeap<int>(a,N);
		H->BuildHeap();
		out << H->print() << endl;
	}
	
	if(type=="double"){
		double** a = new double*[N+1];
		for(int j=1; j<=N; j++){
			a[j]= new double;
			in >> *a[j];
		}
		
		MaxBinaryHeap<double> *H = new MaxBinaryHeap<double>(a,N);
		H->BuildHeap();
		out << H->print() << endl;
	}
}
return 0;
}
