#include<fstream>
using namespace std;

class Cofanetto{
private:
    int x;
    int y;
    int z;
public:
    Cofanetto(int _x, int _y, int _z): x(_x),y(_y),z(_z){}

    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}

    bool isGreaterThan(Cofanetto* c){
        return (c->getX()<x && c->getY()<y && c->getZ()<z);
    }
};

void Ric(Cofanetto** v,int k, int N, int cont, int* max){
    int flag = false;
    for(int i=0; i<N; i++){
        flag = false;
        if(v[k]->isGreaterThan(v[i])){
            Ric(v, i, N, cont+1, max);
            flag = true;
        }
    }

    if(!flag){
        if(cont > *max)
            *max=cont;
        return;
    }
}

int main(){
const int DIM = 100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
        int N=0;
        in >> N;
        Cofanetto* c[N];

        int X=0,Y=0,Z=0;
        for(int j=0; j<N; j++){
            in >> X >> Y >> Z;
            c[j]= new Cofanetto(X,Y,Z);
        }

        int max=0;
        for(int j=0; j<N; j++)
            Ric(c,j,N,1, &max);

        out << max << endl;

        delete c;
}
return 0;
}
