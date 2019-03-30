#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main(){
    int DIM=10;
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n=0;
    string stringa="", sub="";
    for(int i=0; i<DIM; i++){
      in >> n >> sub;
        for(int j=0; j<n; j++){
                cout << j << endl;
            in >> stringa;
            if(stringa.find(sub)!=string::npos) out << stringa << " ";
        }
        out << endl;
    }

return 0;
}

