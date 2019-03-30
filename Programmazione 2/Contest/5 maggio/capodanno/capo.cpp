#include<fstream>
#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

class Invito{
public:
    int inizio;
    int durata;
    int adelina;

    Invito(char i, int d, int a) : inizio(i),durata(d), adelina(a){}
};

bool sortByInizio(const Invito &in, const Invito &ni) { return in.inizio < ni.inizio; }

int maxSum=0;

void ore(vector<Invito> v,int i,int somma){
    if(flag){
        return somma;
    }
     for(int j=i+1; j<v.size(); j++){
        if((v.at(j).inizio + v.at(j).durata <= v.at(k).inizio || v.at(j).inizio >= v.at(k).inizio + v.at(k).durata))
    }
    for(int j=i+1; j<v.size(); j++){
        if((v.at(j).inizio + v.at(j).durata <= v.at(k).inizio || v.at(j).inizio >= v.at(k).inizio + v.at(k).durata))

    }
}
int main(){

const int DIM=1;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
   int N=0, oreTot=0;
   in >> N >> oreTot;

   vector<Invito> v;
   int inizio=0, durata=0;
   in >> inizio >> durata;
   v.push_back(Invito(inizio,durata, 1));
   in >> inizio >> durata;
   v.push_back(Invito(inizio,durata, 0));

   for(int j=0; j<N-2; j++){
        in >> inizio >>durata;
        if((inizio+durata <= v.front().inizio || inizio >= v.front().inizio+v.front().durata))
            v.push_back(Invito(inizio,durata, 0));
   }

   sort(v.begin(), v.end(), sortByInizio);

    for(int j=0; j<v.size(); j++)
        ore(v,j, v.at(j).durata);

   cout << oreTot-maxSum << endl;


}

return 0;
}
