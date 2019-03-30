#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int DIM=10;
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int l=0; l<DIM; l++){
        int n=0;
        in >> n;
        string s[n] = "";
        string t="";
        int count=-1;
        for(int i=0; i<n; i++){
            in >> t;
            bool flag=true, c=true;
            for(int j=0; j<t.length()/2 && flag; j++)
                if(t[j]!=t[t.length()-j-1]){
                    if(c) c=false;
                    else flag=false;
                }


            if(flag){
                count++;
                s[count]=t;
            }
        }
        out << count+1 << " ";
        for(int i=0; i<=count; i++)
            out << s[i] << " ";
        out << endl;
    }

return 0;
}


