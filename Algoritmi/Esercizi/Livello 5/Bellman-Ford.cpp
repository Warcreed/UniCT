#include<fstream>
#include<string>
#include<iostream>
#include<sstream>


using namespace std;

template<class H> class Vector{
private:
    int n,len;
    H** v;
public:
    Vector(int x){
        len=x;
        v=new H*[len];
        n=0;
    }

    Vector<H>* ins(H x){
        if(n==len) return this;
        v[n]=new H(x);
        n++;
        return this;
    }

    H findKey(int indice){
        return *v[indice];
    }

    int findIndex(H x){
        for(int i=0;i<n;i++)
            if(*v[i]==x)
                return i;
        return -1;
    }

    int getSize(){return n;}

    void stampaNodi(){
        for(int i = 0; i < n; i++) cout << *v[i] << " ";
        cout << endl;
    }
};

template<class H>
class Grafo{
    private:
        int nArchi;
        int len;
        H** matrix;
        Vector<H>* nodi;
        H* dist;
        H* pred;

        bool Bellman_Ford(int s){
            for(int i = 0; i < len; i++){
                dist[i] = 101;
                pred[i] = -1;
            }
            dist[s] = 0;
            
            for(int k = 0; k < len-1; k++)
                for(int i = 0; i < len; i++)
                    for(int j = 0; j < len; j++){
                        /* for(int l = 0; l < len; l++) cout << dist[l] << " ";
                            cout << endl; */
                       if(dist[j] > dist[i] + matrix[i][j]){
                            dist[j] = dist[i] + matrix[i][j];
                            pred[j] = j;
                        } 
                    }
                        
            
            for(int i = 0; i < len; i++)
                for(int j = 0; j < len; j++)
                    if(dist[j] > dist[i]+matrix[i][j]) return false;
           
            return true;
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
            nodi = new Vector<H>(len);
            this->len = len;
            nArchi = 0;
        }

        Grafo<H>* insNode(H x){
            nodi->ins(x);
            return this;
        }

        Grafo<H>* insArco(H x, H y, H w){
            int i = nodi->findIndex(x);
            int j = nodi->findIndex(y);
            if(i < 0 || j < 0) return this;
            matrix[i][j] = w;
            nArchi++;
            return this;
        }

        string distanza(H x, H y){
            int i = nodi->findIndex(x);
            int j = nodi->findIndex(y);
            if(i < 0 || j < 0) return " nodo non presente";
           // cout << dist[j] << endl;
            bool check = Bellman_Ford(i);
           //  cout << dist[j] << endl;
            if(!check) return "undef.";
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
    int N = 0, M = 0;
    string type = "";
    for(int i = 0; i < DIM; i++){
        in >> N >> M >> type;
        if(type == "int"){
            Grafo<int>* G = new Grafo<int>(N);
            for(int j = 0; j < N; j++){
                int tmp;
                in >> tmp;
                G->insNode(tmp);
            }
        
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
            out << G->distanza(s,f) << endl;
        }

        if(type == "double"){
            Grafo<double>* G = new Grafo<double>(N);
            for(int j = 0; j < N; j++){
                double tmp;
                in >> tmp;
                G->insNode(tmp);
            }
        
             for(int j = 0; j < M; j++){
                stringstream s, s1, s2;
                string a, a1, a2;
                in >> a >> a1 >> a2;
                s << a.substr(1, a.length());
                s1 << a1;
                s2 << a2.substr(0, a2.length());
                double b, b1, b2;
                s >> b; s1 >> b1; s2 >> b2;
                G->insArco(b, b1, b2);
            }
           
            double s, f;
            in >> s >> f;
            out << G->distanza(s,f) << endl;
        }
    }
    return 0;
}