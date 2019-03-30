#include<fstream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    const int DIM=100;
for(int i=0; i<DIM; i++){
    int N;
    in >> N;
    int temp=0;
    for(int j=0; j<N; j++){
            in >> temp;
            if(temp%2)
               out << temp << " ";
    }
    out << endl;
}
return 0;
}
