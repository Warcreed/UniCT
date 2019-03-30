#include<fstream>
#include<string>

using namespace std;

int indice=0;

void swap(char* s, int i, int j){
    char temp=s[i];
    s[i]=s[j];
    s[j]=temp;

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

void anagramma(char* s, int i, int n, string* out, string prom){
    if(i==n) {
        int l =0;
        for(int k=0; k<prom.length(); k++)
            if(prom[k]=='*') prom[k]=s[l++];
        out[indice++]=prom;
        return;
    }
    for(int j=i; j<n; j++){
        swap(s,i,j);
        anagramma(s, i+1, n, out, prom);
        swap(s,i,j);
    }
}

int main(){

const int DIM=100;
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

    int f=fattoriale(dim);
    indice=0;
    string output[f];

    anagramma(v,0,dim,output,prom);

    for(int j=0; j<f; j++){
        for(int k=j+1; k<f; k++){
            flag=false;
               for(int l=0; l<N && !flag; l++){
                    if(((output[k])[l] != (output[j])[l])) flag=true;
                    if((output[k])[l] < (output[j])[l]) swap(output, k, j);
               }
        }

    }

    for(int j=0; j<f; j++)
       out << output[j] << " ";
    out << endl;
}
return 0;
}



