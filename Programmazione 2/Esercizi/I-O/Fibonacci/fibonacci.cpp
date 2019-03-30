#include<iostream>
#include<fstream>

using namespace std;

int main(){
    const int DIM=10;
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n=0, n1=0, n2=1;
    for(int j=0; j < DIM; j++){
            in >> n;
            cout << n << endl;
            n1=0;
            n2=1;
        for(int i=1; i < n; i++){
            int temp=0;
            temp=n2;
            n2=n2+n1;
            n1=temp;
            cout<< n2 << " " << n1 << endl;
        }
        out << n2 << endl;
    }
return 0;
}
