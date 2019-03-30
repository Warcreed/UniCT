#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

vector<vector<int> > matrice;
int* tempi;
int* P;

void stampa(vector<vector<int> > matrice)
{
	for(int i=0;i<matrice.size();i++)
	 {
	 	cout<<i<<"  ";
	 	for(int k=0;k<matrice[i].size();k++)
	 	 cout<<matrice[i][k]<<" ";

	 	 cout<<endl;
	 }
	 cout<<endl;
}

void stampaDist(int* t,int n)
{
	for(int i=0;i<n;i++)
	 cout<<t[i]<<" ";

	 cout<<endl;
}

void BFS(int Nodo){
    vector<int> coda;
       coda.push_back(Nodo);
       tempi[Nodo]=0;
       while(!coda.empty()){
            int n = coda.back();
            coda.pop_back();
            for(int j=0; j<matrice.size(); j++)
                if(matrice[n][j] && tempi[j]==INT_MAX){
                        coda.insert(coda.begin(),j);
                        tempi[j]=tempi[n]+1;
                    }
            }
}
int main()
{
	ifstream in("input1.txt");
	ofstream out("output.txt");
	const int DIM=100;
    for(int i=0;i<DIM;i++)
    {

        int Nnodi=0, Archi=0, Npasticcerie=0;

        in >> Nnodi >> Archi >> Npasticcerie;


        tempi= new int[Nnodi];
		P = new int[Npasticcerie];

		matrice.resize(Nnodi);

        for(int j=0;j<Nnodi;j++){
            matrice[j].assign(Nnodi,0);
            tempi[j]=INT_MAX;
        }

		for(int j=0;j<Npasticcerie;j++){
            int a;
			in >> a;
			P[j]=a-1;
		}
		for(int j=0;j<Archi;j++){
            int a, b;
			in >> a >> b;
			matrice[a-1][b-1]=matrice[b-1][a-1]=1;
		}

        BFS(0);
        int distPast[Npasticcerie];
        for(int j=0; j<Npasticcerie; j++)
            distPast[j]=tempi[P[j]];

        int sol = INT_MAX;
        for(int j=0; j<Npasticcerie; j++){
            for(int k=0;k<Nnodi;k++)
                tempi[k]=INT_MAX;

            BFS(P[j]);
                sol= (tempi[Nnodi-1]+distPast[j]>0 && tempi[Nnodi-1]+distPast[j]<sol)? tempi[Nnodi-1]+distPast[j] : sol;
       }

    if(sol!=INT_MAX)
            out << sol << endl;
        else
            out << -1 << endl;

    }
}

