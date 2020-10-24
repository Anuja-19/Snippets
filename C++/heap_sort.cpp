#include <iostream>
#include<vector>
using namespace std;
void max_heapify (vector<int>& Arr, int i,int N)
{
    int left = 2*i ;                  
    int right = 2*i +1 ;
    int largest=-1;
    if(left<= N and Arr[left] > Arr[i] )
        largest = left;
    else
        largest = i;
    if(right <= N and Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (Arr[i] , Arr[largest]);
        max_heapify (Arr, largest,N);
    }
}
void build_maxheap (vector<int> Arr)
{
	int N=Arr.size();
    for(int i = N/2 ; i >= 1 ; i-- )
    {
        max_heapify (Arr, i,N) ;
    }
}


void heap_sort(vector<int> &Arr)
{
    int heap_size = Arr.size();
    build_maxheap(Arr);
    for(int i = heap_size; i>=2 ; i-- )
    {
        swap(Arr[ 1 ], Arr[ i ]);
        heap_size = heap_size-1;
        max_heapify(Arr, 1, heap_size);
    }
}
int main() {
	int n=0;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i) cin>>a[i];
	heap_sort(a);
	for(auto x: a) cout<<x<<" ";
	
	
}
