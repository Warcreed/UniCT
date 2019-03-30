#include<iostream>
#include<fstream>

using namespace std;

int main(){
    const int DIM=10;
    int dim=0, comic=0, book=0;

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    for(int i=0; i<DIM; i++){
        fin >> dim >> comic;
        int flag=false;
        for(int j=0; j<dim; j++){
            fin >> book;
            if(comic==book){
                fout << j+1 << endl;
                flag=true;
            }
        }
        if(!flag)
            fout << 0 << endl;
    }
    fin.close();
    fout.close();
return 0;
}

