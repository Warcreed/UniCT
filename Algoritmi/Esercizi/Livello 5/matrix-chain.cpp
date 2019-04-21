/*
    soluzione al problema matrix-chain order, vedere il gitHub di Wornairz per una spiegazione più accurata.
*/
#include<fstream>
#include<iostream>
#include<sstream>
#include<climits>

using namespace std;

class Matrice{
    private:
        int righe, colonne;
    public:
        Matrice(): righe(0), colonne(0){}

        int getCol(){ return colonne; }
        int getRig(){ return righe; }
        void setCol(int c){ colonne = c; }
        void setRig(int r){ righe = r; }
};

int matrixChainOrder(Matrice* m, int N){
    int matrix[N][N];

    for(int i = 0; i < N; i++) matrix[i][i] = 0; // caso banale, valutazione matrice con se stessa, settiamo diagonale a 0

    for(int l = 2; l <= N; l++){                //esprime il numero di matrici considerate in una parentesi all'interno della parentesizzazione, minimo 2
        for(int i = 0; i <= N - l; i++){        //matrice iniziale, indice sinistro della parentesi considerata.
            int j = i + l - 1;                  //indice destro, indica matrice finale da considerare all'interno della parentesi
            matrix[i][j] = INT_MAX;             //si inizializza il valore della matrice
            for(int k = i; k < j; k++){        //indice che scorre da i a j le matrici all'interno del gruppo o catena considerato in una parentesi, cerca la parentesizzazione ottimale nel quale dividere il gruppo
                    int q = matrix[i][k] + matrix[k+1][j] + (m[i].getRig() * m[k].getCol() * m[j].getCol()); //costo della parentesizzazione in esame, dato dalle precedenti valutazioni (progr dinamica) + il caso attuale, dato dalla formula riga * col * col (può variare, nello scritto potrebbe dare una cosa simile, basta variare la formula e sistemare i controlli)
                    if( q < matrix[i][j])   matrix[i][j] = q; //se il costo attuale è migliore del precedente, viene sostituito (ecco spiegata l'inizializzazione ad INT_MAX)
            }
        }
    }
    return matrix[0][N-1];        //il costo della parentesizzaione ottimale si trova nella cella riga 0, colonna N-1
}

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0;
    for(int i = 0; i < DIM; i++){
        in >> N;
        Matrice* m = new Matrice[N];
        for(int j = 0; j < N; j++){
            int r = 0, c = 0;
            string s;
            in >> s;
            stringstream(s.substr(1, s.find('x'))) >> r;
            m[j].setRig(r);
            stringstream(s.substr(s.find('x')+1, s.length()-1)) >> c;
            m[j].setCol(c);
        }
        out << matrixChainOrder(m, N) << endl;
        delete[] m;
    }
    return 0;
}