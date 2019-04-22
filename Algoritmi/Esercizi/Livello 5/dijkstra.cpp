#include<fstream>
#include<climits>
#include<sstream>

using namespace std;

template<class N>
class Nodi{
    private:
        N* nodi;
        int len;
        int n;
    public:
        Nodi(int l) : len(l) {
            nodi = new N[len];
            n = 0;
        }

        void insNodo(N nodo){ if(n < len) nodi[n++] = nodo; }

        int getIndex(N nodo){
            for(int i = 0; i < n; i++)
                if(nodi[i] == nodo) return i;
            return -1;
        }

        N getNodo(int i){ if(i > 0 && i < n) return nodi[i]; }
        int getSize(){ return n; }
};

template<class G>
class Grafo{
    private:
        G** matrix;
        Nodi<G>* nodi;
        int len;
        int nArchi;
        G* dist;
        bool* nodiVisitati;

        int findMin(){                    //funzione che restituisce il minimo nel vettore dist tra i nodi non visitati.
            G min = INT_MAX;
            G tmpNodo = 0;
            for(int j = 0; j < len; j++){
                    if(dist[j] < min && !nodiVisitati[j]){
                        min = dist[j];
                        tmpNodo = j;
                    }
                }
            return tmpNodo;
        }

        void dijkstra(G nodo){
            int nodoIn = nodi->getIndex(nodo);
            nodiVisitati = new bool[len];           //vettore con lunghezza = len = numero di nodi, si occupa di tenere traccia dei nodi visitati se un nodo è visitato non lo prenderò in esame una seconda volta.
            dist = new G[len];                      //vettore delle distanze di dimensione = len = numero di nodi, viene usato per tenere traccia delle distanze da un nodo A (con dist = 0) ad un nodo B.
            for(int i = 0; i < len; i++){           //inizializzo: 
                nodiVisitati[i] = false;            //a false il vettore dei visitati (true = visitato)
                dist[i] = INT_MAX;                  //a INT_MAX = infinito il vettore delle distanze
            }
            dist[nodoIn] = 0;                       //inizializzo la distanza del nodo A con A stesso = 0
            for(int i = 0; i < len; i++){           //ciclo per ogni nodo
                int tmpNodo = findMin();            //trovo il nodo con distanza minima tra i nodi NON visitati
                nodiVisitati[tmpNodo] = true;       //lo prendo in esame e lo pongo a già visitato
                for(int j = 0; j < len; j++)        //ciclo per ogni nodo nel vettore dist[]
                    if(!nodiVisitati[j] && matrix[tmpNodo][j] != 101 && dist[tmpNodo] + matrix[tmpNodo][j] < dist[j])   //valuto che: NON sia già visitato (implica che è già presente un valore ottimo), che esista un arco (101 = NON esiste arco), 
                        dist[j] = dist[tmpNodo] + matrix[tmpNodo][j];                                                   //che la somma tra la distanza del nodo corrente più il peso dell'arco che congiunge A e B, sia migliode del valore già presente in B, eventualmente lo assegno.
            }
        }

    public:
        Grafo(int n){
            len = n;
            matrix = new G*[len];
            for(int i = 0; i < len; i++){
                matrix[i] = new G[len];
                for(int j = 0; j < len; j++)
                    matrix[i][j] = 101;
                matrix[i][i] = 0;
            }   
            nodi = new Nodi<G>(n);
            nArchi = 0;
        }

        void addArco(G a, G b, G w){
            int i = nodi->getIndex(a);
            int j = nodi->getIndex(b);
            if(i < 0 || j < 0) return;
            matrix[i][j] = w;
            nArchi++;
        }

        void addNodo(G a){ nodi->insNodo(a); }

        int getMinDistance(G a, G b){
            int i = nodi->getIndex(a);
            int j = nodi->getIndex(b);
            if(i < 0 || j < 0) return -1;
            dijkstra(a);
            if(dist[j] != 101) return dist[j];
            return -1;
        }
};

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int nNodi = 0, nArchi = 0;
    string type = "";
    for(int i = 0; i < DIM; i++){
        in >> nNodi >> nArchi >> type;    
        if(type == "int"){ 
            Grafo<int>* G = new Grafo<int>(nNodi);
             for(int j = 0; j < nNodi; j++){
                string s1;
                in >> s1;
                int a;
                stringstream(s1) >> a;
                G->addNodo(a);
            }  
            for(int j = 0; j < nArchi; j++){
                string s1, s2, s3;
                in >> s1 >> s2 >> s3;
                int a, b , w;
                stringstream(s1.substr(1, s1.length())) >> a;
                stringstream(s2) >> b;
                stringstream(s3.substr(0, s3.length()-1)) >> w;
                G->addArco(a, b, w);
            }
            int a, b;
            in >> a >> b;
            int dist = G->getMinDistance(a, b);
            if(dist > 0) out << dist << endl;
            else out << "inf." << endl;
        }
        if(type == "double"){
            Grafo<double>* G = new Grafo<double>(nNodi);
             for(int j = 0; j < nNodi; j++){
                string s1;
                in >> s1;
                double a;
                stringstream(s1) >> a;
                G->addNodo(a/10);
            }   
            for(int j = 0; j < nArchi; j++){
                string s1, s2, s3;
                in >> s1 >> s2 >> s3;
                double a, b, w;
                stringstream(s1.substr(1, s1.length())) >> a;
                stringstream(s2) >> b;
                stringstream(s3.substr(0, s3.length()-1)) >> w;
                G->addArco(a, b, w);
            }
            double a, b;
            in >> a >> b;
            double dist = G->getMinDistance(a, b);
            if(dist > 0) out << dist << endl;
            else out << "inf." << endl;
        }
    }
}