#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *,int *);
void heapify(int *,int,int);
void heapsort(int *,int);
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void heapify(int *arr,int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapsort(int *arr,int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(i=n-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,--n,0);
    }
}
void main (void)
{
    int i,j,n,*a;
    FILE *fp1,*fp2;
    printf("\nEnter number of elements in the array:");
    scanf("%d",&n);
    srand(time(NULL));
    a=(int*)calloc(n,sizeof(int));
    fp1=fopen("ip.txt","w+");
    for(j=0;j<n;j++)
        fprintf(fp1,"%d\t",rand()%100);
    rewind(fp1);

    fp2=fopen("op.txt","w");
    for(j=0;j<n;j++)
        fscanf(fp1,"%d",&a[j]);
    heapsort(a,n);
    for(j=0;j<n;j++)
        fprintf(fp2,"%d\t",a[j]);
    fclose(fp1);
    fclose(fp2);
}