#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main(){
    int DIM=10;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n=0;
    for(int i=0; i<DIM; i++){
        in >> n;
        int vett[n];
        int count=0;
        for(int j=0; j<n; j++){
            in >> vett[j];
        }

        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++)
                if(vett[j]==vett[k] && vett[k]){
                    count++;
                    vett[k]=0;
                }
        }


        out << count << endl;
        }

return 0;
}

