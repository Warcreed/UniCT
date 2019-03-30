#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
using namespace std;

class Nodo{
private:
    int r;
    int c;
    char simbolo;
    int costo;
public:
    Nodo(int riga, int colonna, char s): r(riga),c(colonna),simbolo(s), costo(RAND_MAX){}

    int getRiga(){ return r;}
    int getColonna(){return c;}
    char getSimbolo(){ return simbolo;}
    int getCosto(){return costo;}
    void setCosto(int costo){this->costo = costo;}

};

int main(){
const int DIM = 1;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    int C=0, R=0, NumNodi=0;
    in >> C >> R;
    Nodo* map[R][C];
    Nodo* e;
    Nodo* u;
    vector<Nodo*> min;
    vector<Nodo*> visitato;
    vector<Nodo*> root;
    for(int j=0; j<R; j++)
        for(int k=0; k<C; k++){
            char s;
            in >> s;
            map[j][k] = new Nodo(j,k,s);
            if(map[j][k]->getSimbolo()=='E'){
                map[j][k]->setCosto(0);
                e = map[j][k];
            }
            else if(map[j][k]->getSimbolo()=='U')
                u = map[j][k];
            else if(map[j][k]->getSimbolo()=='_')
                NumNodi++;
        }


//    for(int j=0; j<R; j++){
//        for(int k=0; k<C; k++)
//            cout << map[j][k]->getColonna() << " ";
//        cout<<endl;
//    }
        min.push_back(e);
        visitato.push_back(e);
        root.push_back(e);


        int j = root.back()->getColonna();
        int i = root.back()->getRiga();

        for(int k=0; k<2; k++)
            if( j+k<C && j+k>=0 && i-1>=0 && i-1<R)
                if(m[i-1][j+k]=='Q')
                    cout << 1 << endl;
                else{

                     for(int k=0; k<2; k++)
                        if( j+k<C && j+k>=0 && i-1>=0 && i-1<R)
                            if()
                     for(int k=0; k<2; k++)
                        if( j-k<C && j-k>=0 && i+1>=0 && i+1<R)

                        if( j<C && j>=0 && i-2>=0 && i-2<R)

                        if( j<C && j>=0 && i+2>=0 && i+2<R)

                        if( j-2<C && j-2>=0 && i>=0 && i<R)

                        if( j+2<C && j+2>=0 && i>=0 && i<R)


                }

        for(int k=0; k<2; k++)
        if( j-k<C && j-k>=0 && i+1>=0 && i+1<R)
            if(m[i-1][j+k]=='Q')
                    cout << 1 << endl;

        if( j<C && j>=0 && i-2>=0 && i-2<R)
            if(m[i-1][j+k]=='Q')
                    cout << 1 << endl;

        if( j<C && j>=0 && i+2>=0 && i+2<R)
            if(m[i-1][j+k]=='Q')
                    cout << 1 << endl;

        if( j-2<C && j-2>=0 && i>=0 && i<R)
            if(m[i-1][j+k]=='Q')
                    cout << 1 << endl;

        if( j+2<C && j+2>=0 && i>=0 && i<R)
            if(m[i-1][j+k]=='Q')
                    cout << 1 << endl;

        }

}
return 0;
}
