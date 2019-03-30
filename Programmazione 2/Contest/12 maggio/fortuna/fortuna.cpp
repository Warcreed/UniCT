#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

const int DIM=100;
ifstream in("input.txt");
ofstream out("output.txt");

for(int i=0; i<DIM; i++){
    int N=0;
    in >> N;
    vector<int> v;

    for(int j=0; j<2*N; j++){
        int temp=0;
        in >> temp;
        v.push_back(temp);
    }

    int Q=0;
    in >> Q;
    for(int j=0; j<Q; j++){
        int shift=0;
        in >> shift;
        rotate(v.begin(),v.begin()+v.size()-shift%(2*N),v.end());
        int t=v.at(0);
        int k;
        for(k=1; k<N; k++)
            if(v.at(k)<t) t=v.at(k);
        out << t << " ";
        t=v.at(k);
        for(k=k+1; k<2*N; k++)
            if(v.at(k)>t) t=v.at(k);
        out << t << " ";

    }
    out << endl;
}
return 0;
}
