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


int main(){

const int DIM=2;
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

cout << i+1 << ")";
 cout <<endl << "inizio durata adelina" << endl;
    for(int j=0; j<v.size(); j++){
        cout << v.at(j).inizio << "\t" << v.at(j).durata << "\t" << v.at(j).adelina << endl;
    }

//    for(int j=0; j<v.size(); j++){
//         for(int k=0; k<v.size(); k++){
//                if(j!=k)
//                    if(v.at(j).inizio + v.at(j).durata > v.at(k).inizio && v.at(j).inizio < v.at(k).inizio + v.at(k).durata)
//                        if(v.at(k).adelina==1)
//                            v.erase(v.begin()+j);
//                        else if(v.at(j).durata>v.at(k).durata)
//                            v.erase(v.begin()+k);
//                        else if(v.at(j).durata==v.at(k).durata)
//                                if(v.at(j).inizio<=v.at(k).inizio)
//                                    v.erase(v.begin()+k);
//                                else
//                                    v.erase(v.begin()+j);
//         }
//     }
//    int somma = 0, lastSomma=0;
//    for(int j=0; j<v.size(); j++){
//            somma = v.at(j).durata;
//            int flag = true;
//         for(int k=0; k<v.size() && flag; k++){
//                if(j!=k)
//                    if(v.at(j).inizio + v.at(j).durata <= v.at(k).inizio && v.at(j).inizio >= v.at(k).inizio + v.at(k).durata)
//                       for(int l=0; l<v.size(); l++){
//                        if()
//                       }
//
//         }
//         if(flag && somma > lastSomma)
//            lastSomma = somma;
//
//     }

     int j=0, temp=-1, somma=v.front().durata;
     while(j<v.size()){
            int k=j+1;
            while(k<v.size() && (v.at(j).inizio + v.at(j).durata <= v.at(k).inizio && v.at(j).inizio >= v.at(k).inizio + v.at(k).durata)){
                k++;
            }
            k--;
            cout << j << " " << k << " " << somma << endl;
            temp = -1;
            for(int l=k; l<v.size(); l++)
                if((v.at(j).inizio + v.at(j).durata <= v.at(l).inizio || v.at(j).inizio >= v.at(l).inizio + v.at(l).durata))
                    if(v.at(l).durata>=v.at(k).durata && v.at(l).inizio < v.at(k).inizio){
                        temp = l;
                        k = l;
                    }
            if(temp!=-1){
                somma += v.at(temp).durata;
                j = temp;
            }
            else{
                 somma += v.at(k).durata;
                 j=k;
            }

     }

//    int sum=0;
//     cout <<endl << "inizio durata adelina" << endl;
//    for(int j=0; j<v.size(); j++){
//        cout << v.at(j).inizio << "\t" << v.at(j).durata << "\t" << v.at(j).adelina << endl;
//        sum+=v.at(j).durata;
//    }

   cout << endl << "OreTotali = "<< oreTot << endl <<  "oreAcasa = " << oreTot-somma << endl << endl;
//    out << oreTot-somma << endl;

}

return 0;
}
