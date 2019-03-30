#include<fstream>
#include<iostream>
using namespace std;

class Testimone{
public:
    int start;
    int end;

    Testimone(int s, int e):start(s), end(e){}

    int getPeriodo(){return end-start;}
};

void InserimentoOrdinato(Testimone** vett, int N, istream& in){
    int s=0, e=0;
    for(int j=0; j<N; j++){
        in >> s >> e;
        Testimone* t = new Testimone(s,e);
        bool flag=true;
        for(int k=0; k<j && flag; k++){
            if(t->start<vett[k]->start){
                flag=false;

                for(int l=N-1; l>k; l--)
                    vett[l]=vett[l-1];

                vett[k]=t;
            }
        }
        if(flag)
        vett[j]=t;
    }
}
int main(){

const int DIM=100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){

    int N=0;
    in >> N;
    Testimone* t[N];

    InserimentoOrdinato(t,N,in);

    int dist[N-1], orari[N];

    orari[0]= t[0]->start;
    for(int j=1; j<N; j++){
        orari[j]= t[j]->end;
    }

    dist[0]= t[1]->end - t[0]->start;
    for(int j=1; j<N-1; j++){
        dist[j]= t[j+1]->end - t[j]->end;
    }

    bool flag=true, flag1=true;
    int j=0;
    while(flag){
        flag1=false;
        j=0;
        while(j<N-1){
            flag=false;
            int ora = orari[j+1];
            while(dist[j]>dist[j+1] && ora>t[j+1]->start){
                dist[j]--;
                ora--;
                dist[j+1]++;
                flag=true;
                flag1=true;
            }

            if(flag)
                orari[j+1]=orari[j]+dist[j];
            j++;
        }
    }

//    for(int j=0; j<N; j++)
//        cout  << dist[j] << "\t" << orari[j] << endl;

    int min=INT_MAX;
    for(int j=0; j<N-1; j++)
        if(dist[j]<min) min=dist[j];
    min+=1;

    for(int j=0; j<N-1; j++)
        if((orari[j]+min> t[j+1]->start) && (orari[j]+min< t[j+1]->end)) orari[j+1]=orari[j]+min;
        else if(orari[j]+min< t[j+1]->end) orari[j+1]=t[j+1]->start;

    for(int j=0; j<N; j++)
        out  << orari[j] << " ";



    out << endl;
}
return 0;
}

