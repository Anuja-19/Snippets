#include<iostream>
using namespace std;
class digit{
private:
    int i,higher,rem,j,temp;

public:
    void rplhigher(int num,int m){
        higher=num%10;
        temp=num;
        for(i=0;i<=m;i++){
            rem=num%10;
            if(higher<rem){
                higher=rem;
            }
            num=num/10;
        }
        temp=higher;
        for(i=0;i<=m;i++){
            higher=num*10;
            num=higher+temp;
        }
        cout<<"Replaced Num "<<num;
    }
};
int main(){
    int m,num;
    cout<<"No. of Digit ";
    cin>>m;
    cout<<"Enter "<<m<<" digit Number";
    cin>>num;
    digit obj;
    obj.rplhigher(num,m);
}
