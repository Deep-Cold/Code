#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef pair<int,int> PII;
int n,cnt,ans;
int a[N];
vector<PII> ps;
bool have[N],vis[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    vis[0]=vis[n+1]=true;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1;
    int ans=0;
    while(r<=n)
    {
        bool have2=false;
        l=r;
        while(l<=n&&a[l]==0) l++;
        if(l>n) break;
        r=l;
        while(r<=n&&a[r]!=0)
        {
            if(a[r]==2) have2=true;
            r++;
        }
        ps.push_back({l,r-1}),have[cnt++]=have2;
    }
    for(int i=0;i<cnt;i++)
    {
        if(have[i]) vis[ps[i].first-1]=vis[ps[i].second+1]=true;
        for(int j=ps[i].first;j<=ps[i].second;j++) vis[j]=true;
    }
    for(int i=0;i<cnt;i++)
    {
        if(!have[i])
        {
            if(vis[ps[i].first-1]) vis[ps[i].second+1]=true;
            else vis[ps[i].first-1]=true;
        }
    }
    ans=cnt;
    for(int i=1;i<=n;i++) if(!vis[i]) ans++;
    cout<<ans<<endl;
    return 0;
}