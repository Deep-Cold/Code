#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,k,res;
int b[N];
bool vis[N];
stack<int> s;
void Dfs(int now)
{
    if(vis[now])
    {
        res=0;
        while(s.top()!=now)
        {
            s.pop();
            res++;
        }
    }
    s.push(now);
    vis[now]=true;
    Dfs(b[now]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>b[i];
        
    }
    return 0;
}