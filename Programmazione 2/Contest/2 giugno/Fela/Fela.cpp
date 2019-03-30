#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int* tempi;

class Coppia{
public:
    int fine;
    int inizio;
    bool esiste;
    Coppia(): esiste(0), fine(0), inizio(0){}
    Coppia(int i, int j): fine(i), inizio(j), esiste(1){}

};

vector<vector<Coppia>> matrice;

void stampa(vector<vector<Coppia> > matrice)
{
	for(int i=0;i<matrice.size();i++)
	 {
	 	cout<<i<<"  ";
	 	for(int k=0;k<matrice[i].size();k++)
	 	 cout<< matrice[i][k].fine << " " << matrice[i][k].inizio <<"\t";

	 	 cout<<endl;
	 }
	 cout<<endl;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	const int DIM=100;
    for(int i=0;i<DIM;i++)
    {
        int Nnodi=0, Archi=0;

        in>>Nnodi;
		in>>Archi;

		tempi= new int[Nnodi];

		matrice.resize(Nnodi);

		for(int j=0;j<matrice.size();j++){
			matrice[j].assign(Nnodi,Coppia());
			tempi[j]=INT_MAX;
		}

        tempi[0]=0;
        int a, b, l, f;

		for(int j=0;j<Archi;j++){
			in >> a >> b >> l >> f;
			matrice[a][b]=matrice[b][a]=Coppia(l,f);
		}

//       stampa(matrice);
       vector<int> coda;
       coda.push_back(0);
       tempi[0]=0;
       while(!coda.empty()){
            int n = coda.back();
            coda.pop_back();
            //cout << n << endl;
            for(int j=0; j<matrice.size(); j++){
                if(matrice[n][j].esiste){
                    if(tempi[n]+1> matrice[n][j].fine && tempi[n]+1 <= matrice[n][j].inizio && tempi[n]+1 < tempi[j]){
                        coda.insert(coda.begin(),j);
                        tempi[j]=tempi[n]+1;
                    }
                    else if(tempi[n]+ 1 + abs(matrice[n][j].fine-tempi[n]) <= matrice[n][j].inizio && tempi[n]+ 1 + abs(matrice[n][j].fine-tempi[n]) < tempi[j]){
                        coda.insert(coda.begin(),j);
                        tempi[j]=tempi[n]+ 1 + abs(matrice[n][j].fine-tempi[n]);
                    }
                }
            }
//             for(int j=coda.size()-1; j>=0; j--)
//                cout << coda.at(j) << " ";
//                cout << endl;
//            for(int j=0; j<Nnodi; j++)
//                cout << tempi[j] << " ";
//            cout << endl;


       }
       if(tempi[Nnodi-1]!=INT_MAX)
            out << tempi[Nnodi-1] << endl;
        else
            out << -1 << endl;

    }
}

