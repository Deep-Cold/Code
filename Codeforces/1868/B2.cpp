#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int t,n;
int a[N];
int vis[50];
ll sum=0;
vector<int> posi,nega;
inline bool Count(int x)
{
    if(!x) return false;
    int num=0;
    bool type=0;
    if(x<0) type=1,x=-x;
    while(x&1^1) x>>=1,num++;
    if(x==1)
    {
        if(!type) posi.push_back(num);
        else nega.push_back(num);
        return false;
    }
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
    sort(posi.begin(),posi.end());
    sort(nega.begin(),nega.end());
    for(int i=49;i>0;i--)
    {
        if(vis[i])
        {
            if(vis[i]>0)
            {
                while(vis[i]&&nega.size()&&nega.back()==i-1) vis[i]--,vis[i-1]++,nega.pop_back();
            }
            else
            {
                while(vis[i]&&posi.size()&&posi.back()==i-1) vis[i]++,vis[i-1]--,posi.pop_back();
            }
            if(vis[i]) return false;
        }
        while(posi.size()&&posi.back()==i-1) vis[i-1]++,posi.pop_back();
        while(nega.size()&&nega.back()==i-1) vis[i-1]--,nega.pop_back();
    }
    if(vis[0]) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        posi.clear(),nega.clear();
        memset(vis,0,sizeof vis);
        sum=0;
        for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
        if(Check()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}