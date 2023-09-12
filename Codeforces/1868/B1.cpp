#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int t,n;
int a[N];
int vis[50];
ll sum=0;
inline bool Count(int x)
{
    if(!x) return false;
    int num=0;
    bool type=0;
    if(x<0) type=1,x=-x;
    while(x&1^1) x>>=1,num++;
    if(type) vis[num]++;
    else vis[num]--;
    while(x&1) x>>=1,num++;
    if(type) vis[num]--;    
    else vis[num]++;
    return x;
}
inline bool Check()
{
    if(sum%n) return false;
    ll ave=sum/n;
    for(int i=1;i<=n;i++)
        if(Count(a[i]-ave)) return false;
    for(int i=0;i<50;i++)
        if(vis[i]) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(vis,0,sizeof vis);
        sum=0;
        for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
        if(Check()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}