#include<fstream>
#include<sstream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    const int DIM=100;
for(int i=0; i<DIM; i++){
    int c;
    int N;
    int x;
    in >> N >> x;
    int temp=0;
    stringstream s;
    for(int j=0; j<N; j++){
            in >> temp;
            if(temp>x){
                c++;
                s << temp << " ";
            }
    }
    out << c << " " << s.str();
    s.clear();
    c=0;
    out << endl;
}
return 0;
}
