#include<fstream>
#include<string>
#include<iostream>
using namespace std;

void swap(char* s, int i, int j){
    char temp=s[i];
    s[i]=s[j];
    s[j]=temp;

}

int swap1(char* s, int i, int j){
    char temp=s[i];
    s[i]=s[j];
    s[j]=temp;
return true;
}

int swap(string* s, int i, int j){
    string temp=s[i];
    s[i]=s[j];
    s[j]=temp;
}

int fattoriale(int n)
{
  return (n == 1 || n == 0) ? 1 : fattoriale(n - 1) * n;
}

void anagramma(char* s, int i, int n, ostream& out, string prom){
    if(i==n) {

            out << s << " ";
       /* int l =0;
        for(int k=0; k<prom.length(); k++)
            if(prom[k]=='*') prom[k]=s[l++];
        out << prom << " ";
        return;*/
    }
    for(int j=i; j<n; j++){
        swap(s,i,j);
        anagramma(s, i+1, n, out, prom);
        swap(s,i,j);
    }
}

int main(){

const int DIM=3;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    bool flag=true;
    int N=0;
    in >> N;
    char vett[N]={0};

    for(int i=0; i<N; i++)
        in >> vett[i];

    string prom, elim="";
    in >> prom;
    int dim=0;
    for(int j=0; j<prom.length(); j++)
        if(prom[j]=='*') dim++;
        else elim+=prom[j];

    char v[dim] ={0};
    int h=0;

    for(int j=0; j<N; j++){
        flag=false;
        for(int k=0; k<elim.length(); k++)
            if(elim[k] == vett[j]) flag=true;
        if(!flag)
            v[h++]=vett[j];
    }

   /* for(int j=dim-1; j>0 && flag; j--){
            flag=false;
            for(int k=0; k<j; k++)
                if(v[k]>v[k+1])
                flag=swap1(v,k,k+1);
    }*/

    for(int j=0; j<dim; j++){
        for(int k=j+1; k<dim; k++)
                if(v[k]<v[j])
                    swap(v,j,k);
    }

    anagramma(v,0,dim,out,prom);

    out << endl;
}
return 0;
}



