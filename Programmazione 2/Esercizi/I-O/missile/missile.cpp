/*#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main(){
    int DIM=1;
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n=0, VegX,VegY,x,y, X, Y;
    for(int i=0; i<DIM; i++){
        in >> n >> VegX >> VegY >> x >> y;
        for(int j=0; j<n-1; j++){
            in >> X >> Y;
            cout << j << ") " << x << " " << y << "\t\t" << X << " " << Y << "\t\t" << VegX << " " << VegY <<  endl;
            if(abs(X-VegX)< abs(x-VegX) && abs(Y-VegY)< abs(y-VegY)){
                x=X;
                y=Y;
               }
            cout << j << ") " << x << " " << y << "\t\t" << X << " " << Y << "\t\t" << VegX << " " << VegY << endl;
        }
    out << x << " " << y << endl;
    cout <<endl<< x << " " << y << endl<<endl;
    }

return 0;
}*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

short check(short x, short y, short tempx, short tempy){
	return abs(x-tempx)+abs(y-tempy);
}

int main(){
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string line;
	short n;
	short x, y;
	short tempx, tempy, bestx, besty;
	short best, att;
	while(getline(infile, line)){
		best = 1001;
		istringstream iss(line);
		iss >> n >> x >> y;
		for(int i=0; i<n; i++){
			iss >> tempx >> tempy;
			att = check(x, y, tempx, tempy);
			if(att<best){
				best = att;
				bestx = tempx;
				besty = tempy;
			}
		}
		outfile << bestx << " " << besty << "\n";
	}
	return 0;
}
