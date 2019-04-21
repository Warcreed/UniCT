#include<fstream>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

template<class H>
class Grafo{
    private:
        int nArchi;
        int len;
        H** matrix;
        H* dist;
        H* pred;

        void Bellman_Ford(int s, int K){
            for(int i = 0; i < len; i++){
                dist[i] = 101;
                pred[i] = -1;
            }
            dist[s] = 0;
            
            for(int k = 0; k < K; k++)
                for(int i = 0; i < len; i++)
                    for(int j = 0; j < len; j++){
                        /* for(int l = 0; l < len; l++) cout << dist[l] << " ";
                            cout << endl; */
                       if(dist[j] > dist[i] + matrix[i][j]){
                            dist[j] = dist[i] + matrix[i][j];
                            pred[j] = j;
                        } 
                    }
        }

    public:
        Grafo(int len){
            matrix = new H*[len];
            dist = new H[len];
            pred = new H[len];
            for(int i = 0; i < len; i++){
                dist[i] = 101;
                pred[i] = 101;
                matrix[i] = new H[len];
                for(int j = 0; j < len; j++){
                     matrix[i][j] = 101;
                }     
            }
            this->len = len;
            nArchi = 0;
        }

        Grafo<H>* insArco(H i, H j, H w){
            if(i < 0 || i > len || j < 0 || j > len) return this;
            matrix[i][j] = w;
            nArchi++;
            return this;
        }

        string distanza(H i, H j, H K){
            if(i < 0 || i > len || j < 0 || j > len) return " nodo non presente";
           // cout << dist[j] << endl;
            Bellman_Ford(i, K);
           //  cout << dist[j] << endl;
            if(dist[j] != 101){
                stringstream s;
                s << dist[j];
                return s.str();
            }
            return "inf.";
        }
        void stampaMatrice(){
             for(int i = 0; i < len; i++){
                for(int j = 0; j < len; j++)
                    cout << matrix[i][j] << " ";
                cout << endl;
             }
                 
        // nodi->stampaNodi();
        }
};

int main(){
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N = 0, M = 0, K = 0;
    for(int i = 0; i < DIM; i++){
        in >> N >> M >> K;
        Grafo<int>* G = new Grafo<int>(N);
       
             for(int j = 0; j < M; j++){
                stringstream s, s1, s2;
                string a, a1, a2;
                in >> a >> a1 >> a2;
                s << a.substr(1, a.length());
                s1 << a1;
                s2 << a2.substr(0, a2.length());
                int b, b1, b2;
                s >> b; s1 >> b1; s2 >> b2;
                G->insArco(b, b1, b2);
            }
           
            int s, f;
            in >> s >> f;
            out << G->distanza(s,f, K) << endl;
        }
    return 0;
}