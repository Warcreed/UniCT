#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int DIM=10;
    ifstream in("input.txt");
    ofstream out("output.txt");

    int m[100][100]={0};
    int n, Xi, Yi, Xf, Yf, max=0;
    for(int i=0; i<DIM; i++){
        for(int k=0; k<100; k++)
            for(int h=0; h<100; h++)
                m[k][h]=0;

        max=0;
        in >> n;
        for(int j=0; j<n; j++){
                in >> Xi >> Yi >> Xf >> Yf;
                for(int k=Xi; k<=Xf; k++)
                    for(int h=Yi; h<=Yf; h++){
                         (m[k][h])++;
                         max=(m[k][h]>max)? m[k][h]:max;
                    }
            }
        out << max << endl;
    }
return 0;
}


