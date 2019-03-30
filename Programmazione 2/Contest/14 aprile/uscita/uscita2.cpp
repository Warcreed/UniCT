#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int minimo, C=0, R=0;

int numR[] = {-1,-1,-1,0,+1,+1,+1,0,-2,+2,0,0};
int numC[] = {-1,0,+1,+1,+1,0,-1,-1,0,0,+2,-2};

class Nodo{
private:
    int r;
    int c;
    char simbolo;
public:
    Nodo(int rig, int col, char simb): r(rig), c(col), simbolo(simb){}

    int getRiga(){ return r;}
    int getColonna(){return c;}
    char getSimbolo(){ return simbolo;}
};
void root(Nodo*** map, Nodo* e,int costo, int maxPassi, vector<Nodo*> n){
    //cout << costo << "\t" << n.back()->r << " " << n.back()->c << endl;
    if(map[e->getRiga()][e->getColonna()]->getSimbolo() =='U'){
        //cout << minimo << endl;
        if(costo<minimo)
        minimo=costo;

        return;
    }
    if(costo >= maxPassi)
        return;

    bool flag = false;
      for(int k=0; k<12; k++){
        bool f = find(n.begin(), n.end(), n.back()) != n.end();
        cout << f << endl;
//        if ((i+numR[k] >= 0) && (i+numR[k] < R) && (j+numC[k] >= 0) && (j+numC[k] < C) && map[i+numR[k]][j+numC[k]]!='X' && !f){
//            flag = true;
//            n.push_back(p);
//            //root(map,R,C,i+numR[k],j+numC[k],costo+1, maxPassi, n);
//
//         }
      }
        if(!flag)
            return;

}

int main(){
const int DIM =3;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    int x =0, y = 0, maxPassi=0;
    in >> C >> R;

    Nodo* map[R][C];
    Nodo* e;
    for(int j=0; j<R; j++)
        for(int k=0; k<C; k++){
            char s;
            in >> s;
            map[j][k] = new Nodo(j,k,s);
            if(map[j][k]->getSimbolo()=='E'){
                e = map[j][k];
            }
            else if(map[j][k]->getSimbolo()=='_')
                maxPassi++;
        }

//    for(int j=0; j<R; j++){
//        for(int k=0; k<C; k++)
//            cout << m[j][k] << " ";
//        cout<<endl;
//    }
        vector<Nodo*> n;
        n.push_back(e);
        minimo=INT_MAX;
        root(map,e,0,maxPassi, n);
//        int min=RAND_MAX;
//        for(int k=0; k<costoP.size(); k++)
//            min = (costoP.at(k)<min)? costoP.at(k) : min;
//        cout<< endl << "min = " << min << endl;

        out << minimo << endl;
    n.clear();
}
return 0;
}
