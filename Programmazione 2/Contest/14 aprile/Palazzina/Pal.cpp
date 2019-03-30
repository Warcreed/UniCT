#include<fstream>

using namespace std;
void scambia(int* v,int i, int j)
{
    int temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}
int partizione(int *v,int b,int e)
{
    int i=b-1,j=e+1;
    int p=v[b];
    while(1)
    {
        do i++; while(v[i]<p);
        do j--; while(v[j]>p);
        if(i<j)
            scambia(v,i,j);
        else
            return j;
    }
}
void quickSort(int *v,int b, int e)
{
    if(b>=e)
        return;

    int j=partizione(v,b,e);
    quickSort(v,b,j);
    quickSort(v,j+1,e);
}

int main()
{
    const int DIM = 100;
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int k=0;k<DIM;k++){
        int N=0;
        in>>N;
        int* v=new int[N];

        for(int i=0;i<N;i++)
            in>>v[i];

        quickSort(v,0,N-1);

        int i=0, j=N-2, T=0;
        while(N!=2 && N!=3){
            T+=v[i+1]+v[i]+v[j+1]+v[i+1];
            N-=2;
            j=N-2;
        }

        if(N==2)
            T+=v[i+1];
        else
            T+=v[0]+v[1]+v[2];

        out<<T<<endl;
        delete [] v;
    }
return 0;
}
