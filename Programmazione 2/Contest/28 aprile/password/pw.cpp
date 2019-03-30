#include<fstream>
#include<iostream>

using namespace std;

int main(){

const int DIM=100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
   int N=0, M=0;
   in >> N >> M;

   string text="";
   string pw="";
   string tmp="";
   in >> text;

int counter=0, lastcount=0;
    for(int j=0; j<N-M; j++){
        counter=0;
        tmp = text.substr(j,M);
        for(int k=0; k<N-M; k++)
            if(tmp == text.substr(k,M))
                counter++;
            else{
                int word=0;
                bool flag=false;
                for(int l=0; l<M && !flag; l++){
                   flag=true;
                    if(tmp[l]==text[k]){
                            flag=false;
                            word++;
                    }
                    else{
                        int dist=0;
                        while(dist<4 && flag){
                            if(tmp[l]==text[k+dist]){
                                flag=false;
                                word++;
                            }
                            dist++;
                        }
                        }
                   }

                //cout << "\t" << word << endl;
                    if(word==M)
                       counter++;
               }

        if(counter>lastcount){
            lastcount=counter;
            pw = tmp;
        }
    }

    out << pw << endl;

}

return 0;
}

