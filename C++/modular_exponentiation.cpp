#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1e9+7;
ll solve(ll a,ll b)
{
 
    if(b==0)
        return 1;
    a=a%mod;
    ll res=(solve(a,b/2)%mod);
    res=(res*res)%mod;
    if(b%2!=0)
    res*=a;
    return res%mod;
}
int main()
{
    int t;
    cin>>t;
    //cout<<mod<<"\n";
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<"\n";
    }
}
