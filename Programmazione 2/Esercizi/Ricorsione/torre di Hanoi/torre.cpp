#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;


void hanoi(int n, char A, char B, char C){
    //A = sorgente
    //B = destinazione
    //C = appoggio

    if(n==1){
        cout << " Sposta un disco da " << A << " in " << B << endl;
        return;
    }
    hanoi(n-1, A, C, B);
    hanoi(1, A, B, C);
    hanoi(n-1, C, B, A);
}
int main(){
    char A = 'A';
    char B = 'B';
    char C = 'C';


    hanoi(4,A,C,B);
return 0;
}


