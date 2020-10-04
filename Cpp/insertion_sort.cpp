#include <iostream>

using namespace std;

void insertion_sort(int a[], int n){
     int i, j, s, p;
     for(i=0; i<n; ++i){
         s = a[i];
         p = i;

         for(j=i; j>0; --j)
            if(s<a[j-1])
                p = j-1;

         for(j=i; j>p; --j)
            a[j] = a[j-1];

         a[p] = s;
    }
}

int main()
{
     int a[100], n, i;

     cout<<"How many elements do you want to enter : ";
     cin>>n;

     cout<<"\nEnter elements: ";
     for(i=0; i<n; ++i)
         cin>>a[i];


     cout<<"\nThe given array is : ";
     for(i=0; i<n; ++i)
        cout<<a[i]<<" ";

     insertion_sort(a, n);

     cout<<"\nThe sorted array is : ";
     for(i=0; i<n; ++i)
        cout<<a[i]<<" ";

     cout << endl;

     return 0;
}

