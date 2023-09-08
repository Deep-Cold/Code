#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,k;
int a[N];
bool vis[N];
inline int Add(int a,int b)
{
    if(a+b>=n+1) return a+b-n-1;
    if(a+b<=0) return a+b+n+1;
    return a+b;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<=n;i++) vis[i]=false;
        for(int i=1;i<=n;i++) cin>>a[i],vis[a[i]]=true;
        for(int i=0;i<=n;i++) if(!vis[i]) a[n+1]=i;
        k%=n+1;
        for(int i=1;i<=n;i++) cout<<a[Add(i,-k)]<<' ';
        cout<<endl;
    }
    return 0;
}