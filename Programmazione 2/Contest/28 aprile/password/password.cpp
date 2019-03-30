#include<fstream>
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
using namespace std;

class Elemento{
public:
    char c;
    int pos;
    int occorrenza;

    Elemento(char el, int p, int o) : c(el),pos(p),occorrenza(o){}
};

bool sortByOccorrenze(const Elemento &el, const Elemento &le) { return el.occorrenza > le.occorrenza; }
bool sortByPos(const Elemento &el, const Elemento &le) { return el.pos < le.pos; }

int main(){

const int DIM=3;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
   int N=0, M=0;
   in >> N >> M;

   string text="";
   string pw="";
   in >> text;

    vector<char> visti;
    vector<Elemento> c;
    for(int k=0; k<N; k++){
       int counter=0;
        if(find(visti.begin(), visti.end(), text[k]) != visti.end()) {}
        else{

        char cha = text[k];
            for(int j=0; j<N; j++)
                if(cha == text[j])
                    counter++;
//            for(int j=0; j<c.size(); j++)
//                if( counter > c.at(j).occorrenze && k> c.at(j).pos)
//                    c.insert(c.begin()+j,Elemento(c,k,counter));
                c.push_back(Elemento(cha,k,counter));
                visti.push_back(cha);
        }
        }

    vector<Elemento> tmp(c);
    sort(c.begin(), c.end(), sortByOccorrenze);

 for(int j=0; j<tmp.size(); j++)
        cout << tmp.at(j).c << " " << tmp.at(j).pos << " " << tmp.at(j).occorrenza << endl;

    vector<Elemento>password;
    int pos=0;


    for(int j=0; j<M; j++){
         Elemento temp = c.at(0);

        for(int k=1; k<c.size(); k++)
            if(c.at(k).occorrenza > temp.occorrenza){
                temp = c.at(k);
                pos = k;

            }

        password.push_back(temp);
        c.erase(c.begin()+pos);


    }

     sort(password.begin(), password.end(), sortByPos);



    for(int j=0; j<password.size(); j++)
        pw += password.at(j).c;

//     for(int j=0; j<c.size(); j++)
//        cout << c.at(j).c << " " << c.at(j).pos << " " << c.at(j).occorrenza << endl;
//    int lastcount=0;
//    for(int p=0; p<c.size()-M; p++){
//        string temp="";
//        for(int j=p; j<M+p; j++)
//            temp+= c.at(j).c;
//        cout << temp << endl;
//        int counter=0;
//        for(int k=0; k<N-M; k++){
//            counter=0;
//                int word=2;
//                for(int l=0; l<M-1; l++){
//                   int dist=0;
//                   bool flag=true;
//                   while(dist<4 && flag){
//                      //cout << "j= " << j << " " << temp[l] << " " << text[j+(dist)] << "\t" << dist << endl;
//                       if(temp[l]==text[k+(dist++)]){
//                            flag=false;
//                            word++;
//                       }
//                   }
//                }
//                //cout << "\t" << word << endl;
//                if(word==M)
//                   counter++;
//        }
//
//            if(counter>lastcount){
//                lastcount = counter;
//                password = temp;
//            }
//    }




    cout << pw << endl;

}

return 0;
}

