#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    const int DIM=100;
for(int i=0; i<DIM; i++){
    int N=0;
    in >> N;
    int A,B;
    char o;
    for(int j=0; j<N; j++){
            in >> A >> o >> B;
            switch(o){
                case '+':out << A+B << " ";
                        break;
                case '-':out << A-B << " ";
                        break;
                default: out << A*B << " ";
                        break;
            }
    }
    out << endl;
}
return 0;
}
