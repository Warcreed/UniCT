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

int numR[] = {-1,-1,-1,0,+1,+1,+1,0,-2,+2,0,0};
int numC[] = {-1,0,+1,+1,+1,0,-1,-1,0,0,+2,-2};

bool isValid(int r, int c, int R, int C){
    return (r >= 0) && (r < R) && (c >= 0) && (c < C);
}

int main(){
const int DIM = 3;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    int C=0, R=0, NumNodi=0;
    in >> C >> R;
    Nodo* map[R][C];
    Nodo* e;
    Nodo* u;
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
        int costo = RAND_MAX;
        bool visitata[R][C] = {false};

        visitata[e->getRiga()][e->getColonna()]=true;

        vector<Nodo*> root;
        vector<Nodo*> min;
        vector<Nodo*> visitato;
        min.push_back(e);
        root.push_back(e);

        while(!root.empty()){
            for(int l=0; l<12; l++){
                Nodo* corrente = root.front();
                visitata[corrente->getRiga()][corrente->getColonna()]=true;;
                Nodo* minimo;

                if(corrente->getSimbolo()=='U'){
                    cout << corrente->getCosto() << endl;
                    break;
                }

            for(int k=0; k<12; k++){

                int x = corrente->getRiga()+ numR[k];
                int y = corrente->getColonna()+ numC[k];


                if (isValid(x, y, R, C) && map[x][y]->getSimbolo()!='X' && map[x][y]->getCosto()>corrente->getCosto()+1 && !visitata[x][y]){
                    map[x][y]->setCosto(corrente->getCosto()+1);

//                    if(map[x][y]->getCosto() < costo){
//                        costo = map[x][y]->getCosto();

                    }
                    if (isValid(x, y, R, C) && map[x][y]->getSimbolo()!='X' && !visitata[x][y])
                            minimo =  map[x][y];
                }


            }
            if(l%2==0){
                root.pop_back();

            }

            else{
                root.push_back(minimo);
                min.push_back(minimo);
            }

        }

        }

        cout << endl;

//        for(int k=0; k<2; k++)
//            if( j+1<C && j+1>=0 && i+k>=0 && i+k<R)
//
//        for(int k=0; k<2; k++)
//        if( j-k<C && j-k>=0 && i+1>=0 && i+1<R)
//
//        if( j<C && j>=0 && i-2>=0 && i-2<R)
//
//        if( j<C && j>=0 && i+2>=0 && i+2<R)
//
//        if( j-2<C && j-2>=0 && i>=0 && i<R)
//
//        if( j+2<C && j+2>=0 && i>=0 && i<R)

        }
return 0;
}
