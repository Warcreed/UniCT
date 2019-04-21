#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

template<class T> 
class Nodo{
    private:
        T key;
        Nodo<T> *left, *right, *parent;
        int color;
    public:
        Nodo(T key){
            this->key = key;
            left = right = parent = NULL;
        }

        T getKey(){ return key;}
        void setKey(T key){ this-> key = key;}
        int getColor(){ return color;}
        void setColor(int color){ this-> color = color;}
        Nodo<T>* getLeft(){ return left;}
        void setLeft(Nodo<T>* n){ this-> left = n;}
        Nodo<T>* getRight(){ return right;}
        void setRight(Nodo<T>* n){ this-> right = n;}
        Nodo<T>* getParent(){ return parent;}
        void setParent(Nodo<T>* n){ this-> parent = n;}
};

template<class T>
class BSTree{
    private:
        Nodo<T>* root;
        int size;
        
        //visite
        void _inorder(Nodo<T>* n, ofstream& out){
            if(n != NULL){
                _inorder(n->getLeft(), out);
                out << n->getKey() << " ";
                _inorder(n->getRight(), out);
            }
        }

        void _preorder(Nodo<T>* n, ofstream& out){
            if(n != NULL){
                out << n->getKey() << " ";
                _preorder(n->getLeft(), out);
                _preorder(n->getRight(), out);
            }
        }

        void _postorder(Nodo<T>* n, ofstream& out){
            if(n != NULL){            
                _postorder(n->getLeft(), out);
                _postorder(n->getRight(), out);
                out << n->getKey() << " ";
            }
        }
    protected:
        Nodo<T>* _getRoot() {return root;}

        Nodo<T>* _minimo(Nodo<T>* n){
            if(n == NULL) return n;
            Nodo<T>* tmp = n;
            while(tmp->getLeft()) tmp = tmp->getLeft();
            return tmp;
        }

        Nodo<T>* _massimo(Nodo<T>* n){
            if(n == NULL) return n;
            Nodo<T>* tmp = n;
            while(tmp->getRight()) tmp = tmp->getRight();
            return tmp;
        }

        Nodo<T>* _successore(Nodo<T>* n){
            if(n == NULL) return n;
            if(n->getRight()) return _minimo(n->getRight());
            Nodo<T>* tmp = n->getParent();
            while(tmp != NULL &&  tmp->getKey() <= n->getKey()) tmp = tmp->getParent();
            return tmp;
        }

        Nodo<T>* _predecessore(Nodo<T>* n){
            if(n == NULL) return n;
            if(n->getLeft()) return minimo(n->getLeft());
            Nodo<T>* tmp = n->getParent();
            while(tmp != NULL && tmp->getKey() >= n->getKey()) tmp = tmp->getParent();
            return tmp;
        }

        Nodo<T>* _ricerca(T key){
            Nodo<T>* n = root;
            while(n!=NULL && n->getKey() != key){
                if(key > n->getKey()) n = n->getRight();
                else n = n->getLeft(); 
            }
            return n;
        }
        
        void _cancellaNodo(T key){
            Nodo<T>* n = _ricerca(key);
            if(!n) return;
            Nodo<T>* p = n->getParent();
            //n solo un figlio (destro o sinistro)
            if(!n->getLeft() || !n->getRight()){
                Nodo<T>* f = n->getRight();
                if(!f) f = n->getLeft();

                if(p) root = f;
                else if(n == p->getLeft()) p->setLeft(f);
                    else p->setRight(f);
                
                if(f) f->setParent(p);
            }
            else{
            //n ha entrambi i figli
                Nodo<T>* succ = _successore(n);
                _cancellaNodo(succ->getKey());
                n->setKey(succ->getKey());
                delete succ;
            }
        }

        BSTree<T>* _rightRotate(Nodo<T>* y){
            Nodo<T>* x = y->getLeft();
            y->setLeft(x->getRight());
            x->setRight(y);
            Nodo<T>* p = y->getParent();
            if(p) root = x;
            else if(y == p->getLeft()) p->setLeft(x);
            else p->setRight(x);
            x->setParent(p);
            y->setParent(x);
            y->getLeft()->setParent(y);
            return this;
        }

        BSTree<T>* _leftRotate(Nodo<T>* y){
            Nodo<T>* x = y->getRight();
            y->setRight(x->getLeft());
            x->setLeft(y);
            Nodo<T>* p = y->getParent();
            if(p) root = x;
            else if(y == p->getRight()) p->setRight(x);
            else p->setLeft(x);
            x->setParent(p);
            y->setParent(x);
            y->getRight()->setParent(y);
            return this;
        }
    
    public:
        BSTree(){
            root = NULL;
            size = 0;
        }

        int getSize(){ return size;}

        void preorder(ofstream& out){
            _preorder(root, out);
            out << endl;
        }
        void inorder(ofstream& out){
            _inorder(root, out);
            out << endl;
        }
        void postorder(ofstream& out){
            _postorder(root, out);
            out << endl;
        }

        BSTree<T>* inserisciNodo(T key){
            Nodo<T>* tmp = root;
            Nodo<T>* p = NULL;
            while(tmp != NULL){
                p = tmp;
                if(key > tmp->getKey()) tmp = tmp->getRight();
                else tmp = tmp->getLeft();
            }
            Nodo<T>* n = new Nodo<T>(key);
            if(!p) root = n;
            else if(key > p->getKey()) p->setRight(n);
            else p->setLeft(n);
            n->setParent(p);
            size++;
            return this;
        }

        BSTree<T>* leftRotate(T key){
            Nodo<T>* n = _ricerca(key);
            if(n && n->getRight()) _leftRotate(n);
            return this;
        }
        
        BSTree<T>* rightRotate(T key){
            Nodo<T>* n = _ricerca(key);
            if(n && n->getLeft()) _rightRotate(n);
            return this;
        }
        void cancellaNodo(T key){
            _cancellaNodo(key);
        }
};

int main(){
    const int DIM = 1;
    ifstream in("input.txt");
    ofstream out("output.txt");
    string type = "", orderType = "";
    int N = 0, M = 0;
    for(int i = 0; i < DIM; i++){
        in >> type >> N >> M >> orderType;
        if(type=="int"){
            BSTree<int>* tree = new BSTree<int>();
            for(int j = 0; j < N; j++){
                in >> type;
                stringstream s;
                if(type[0] == 'i'){
                    s << type.substr(4, type.length());
                    int val;
                    s >> val;
                    tree->inserisciNodo(val);
                }
                else{
                    s << type.substr(5, type.length());
                    int val;
                    s >> val;
                    tree->cancellaNodo(val);
                }
            }
            for(int j = 0; j < M; j++){
                in >> type;
                stringstream s;
                tree->postorder(out);
                if(type[0] == 'r'){
                    s << type.substr(6, type.length());
                    int val;
                    s >> val;
                    cout << val << endl;
                    tree->rightRotate(val);
                }
                else{
                    s << type.substr(5, type.length());
                    int val;
                    s >> val;
                    tree->leftRotate(val);
                }
            }
            if(orderType=="preorder") tree->preorder(out);
            else if(orderType=="inorder") tree->inorder(out);
            else tree->postorder(out);
        }
        
    }
    in.close();
    out.close();
}