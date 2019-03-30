#include<iostream>
#include<fstream>

using namespace std;

int main(){
const int DIM = 10;

ifstream in("input.txt");
ofstream out("output.txt");
bool flag=false;
int n=0;
string diametro = "", max="";
   for(int i=0; i< DIM; i++){
        in >> n;
        cout <<"N = "<< n << endl << endl;
        in >> max;
        for(int j=1; j < n ; j++){
            flag=false;
            in >> diametro;
            cout << "D = " << diametro << endl << "M = " << max << endl;
            if(diametro.length() > max.length()) max=diametro;
            else if(diametro.length() == max.length()){
                    for(int s=0; s < diametro.length() && !flag; s++){
                        if((int)diametro[s]>(int)max[s] ){
                            flag=true;
                            max=diametro;
                        }
                        else if((int)diametro[s]<(int)max[s])
                                flag=true;
                    }
                 }
        }
        out << max << endl;
    }
return 0;
}
