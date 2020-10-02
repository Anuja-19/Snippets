#include<iostream>
using namespace std;
class sorting{
private:
    int i,j,temp,item,lb,ub,mid,pos;
public:
    bubblesort(int ar[10],int n){
        for(i=0;i<=n-1;i++){
            for(j=0;j<=n-1-i;j++){
                if(ar[j]>ar[j+1]){
                    temp=ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=temp;
                }
            }
        }
    }
    
    binarysearch(int ar[10]){
        lb=0;
        ub=9;
        pos=0;
        cout<<endl<<"BINARY SEARCH"<<endl;
        cout<<"Enter Number to Search";
        cin>>item;
        for(i=lb;i<=ub;i++){
            mid=(lb+ub)/2;
            if(item==ar[mid]){
                pos=mid+1;
            }
            else if(item>ar[mid]){
                lb=mid+1;
            }
            else if(item<ar[mid]){
                ub=mid-1;
            }
        }
        if(pos==0){
            cout<<"Number not found"<<endl;
        }
        else{
            cout<<"Number found at position "<<pos<<endl;
        }
    }

};

int main(){
    sorting obj;
    int i,n;
    int ar[100];
	  cout<<"How many Elements you want to enter? ";
	  cin>>n;

	  for(i=0;i<n;i++){
		  cout<<"Input Element ";
		  cin>>ar[i];
	  }

    cout<<"Without Sorted\t";
    for(i=0;i<=n;i++){
        cout<<ar[i]<<"\t";
    }
    obj.bubblesort(ar,n);
    cout<<endl<<"        Sorted\t";
    for(i=0;i<=9;i++){
        cout<<ar[i]<<"\t";
    }    
    obj.binarysearch(ar);

}
