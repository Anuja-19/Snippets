#include <iostream>
using namespace std;

void insertionSort(int ar[],int n)
{
    if(n<=1)
    return;
    insertionSort(ar,n-1);
    int y=ar[n-1];                 //last number is taken as y
    int j=n-2;
    while(j>=0 && ar[j]>y)
    {
        ar[j+1] = ar[j];
        j--;
    }
    ar[j+1]=y;
}

void printArray(int ar[], int n)
{
    int i=0;
    while(i<n)
    {
        cout<<ar[i]<<" ";
        i++;
    }
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    insertionSort(ar,n);
    printArray(ar,n);
    return 0;
}
