#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

void InserimentoOrdinato(int* vett, int N, istream& in){
    int temp=0;
    for(int j=0; j<N; j++){
        in >> temp;
        bool flag=true;
        for(int k=0; k<j && flag; k++)
            if(temp>vett[k]){
                flag=false;
                for(int l=j+1; l>k; l--)
                    vett[l]=vett[l-1];
                vett[k]=temp;
            }
        if(flag)
        vett[j]=temp;
    }
}

void stampa(int* v, int N){
    for(int i=0; i<N; i++)
        cout << v[i] << " ";
    cout << endl;
}
template<class T>
void stampa(vector<T> v){
    for(int i=0; i<v.size(); i++)
        cout << v.at(i) << " ";
    cout << endl;
}
void stampa1(vector<vector<int>> v){
    for(int i=0; i<v.size(); i++){
        for(int k=0; k<v.at(i).size(); k++)
        cout << v.at(i).at(k) << " ";
    cout << endl;
    }
    cout << endl;
}
int main(){

const int DIM=1;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
   int N,R;
   N=R=0;
   in >> N >> R;
   int v[N];
   InserimentoOrdinato(v, N, in);
   // stampa(v,N);


   vector<int> s;
   vector<int> pos;
   vector<vector<int>> sol;
   vector<int> visitato;

   for(int l=0; l<N/2; l++){
        bool flag=false;
        int j=l;
        int sum=0;
        s.clear();
        pos.clear();
        while(!flag){

                for(j;j<N;j++){
                   // int t = find (visitato.begin(), visitato.end(), v[j]);
                    while(sum+v[j]<=R){
                            s.push_back(v[j]);
                            pos.push_back(j);
                            sum+=v[j];
                   // stampa(s);
                    }

                }

                if(sum==R)
                    flag=true;
                else{
                    sum-=s.back();
                    s.pop_back();
                    j=pos.at(pos.size()-1)+1;
                    pos.pop_back();

                }
        }
        if(flag){
            sol.push_back(s);
        }

   }

   vector<int> min=sol.at(0);

   for(int j=1; j<sol.size(); j++){

    if(sol.at(j).size()<min.size()) min=sol.at(j);
    else if(sol.at(j).size()==min.size()){
            bool flag=false;
            int k=0;
            while(!flag && k<min.size()){
                if(sol.at(j).at(k)<min.at(k)){
                        flag = true;
                }
                else if(sol.at(j).at(k)==min.at(k))
                        k++;
                else
                    min=sol.at(j);

            }
       if(!flag)
            min=sol.at(j);
    }
   }
   sol.clear();
    cout << "CAMBIOOO" << endl;
    reverse(&v[0], &v[N]);

   for(int l=0; l<N/2; l++){
        bool flag=false;
        int j=l;
        int sum=0;
        s.clear();
        pos.clear();
        while(!flag){

                for(j;j<N;j++)
                    while(sum+v[j]<=R && s.size()<=min.size()){
                            s.push_back(v[j]);
                            pos.push_back(j);
                            sum+=v[j];
                   // stampa(s);
                    }
                if(sum==R)
                    flag=true;
                else{
                    sum-=s.back();
                    s.pop_back();
                    j=pos.at(pos.size()-1)+1;
                    pos.pop_back();
                }
            stampa(s);
        }
        if(flag){
            sol.push_back(s);
        }

   }


    for(int j=min.size()-1; j>=0; j--)
        cout << min.at(j) << " ";
    cout << endl;

   }
return 0;
}
