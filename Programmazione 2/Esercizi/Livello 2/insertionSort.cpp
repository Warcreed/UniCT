#include<fstream>
#include<iostream>
using namespace std;
void swap(int* v, int i, int j){
    int tmp = v[i];
    v[j]=v[i];
    v[i]=tmp;
}

int insertionSort(int arr[], int n)
{
   int i, key, j, counter=0;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
           counter++;
       }
       arr[j+1] = key;
   }
   return counter;
}
int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    const int DIM=100;
for(int i=0; i<DIM; i++){
    int N=0;
    in >> N;
    int v[N];
    for(int j=0; j<N; j++)
        in >> v[j];

    out << insertionSort(v,N) << endl;;
}
return 0;
}
