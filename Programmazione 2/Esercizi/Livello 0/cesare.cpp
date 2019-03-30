#include<fstream>
#include<iostream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    const int DIM=100;
for(int i=0; i<DIM; i++){
    int N;
    string text;
    in >> N >> text;
    for(int j=0; j<N; j++){
           text[j]=(char)((((int)text[j]-97+3)%26)+97);
    }
    out << text << endl;
}
return 0;
}
