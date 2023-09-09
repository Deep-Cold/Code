#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,n,m,k,x,y;
int xi[N],yi[N];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
inline bool Check(int a,int b)
{
    return (abs(a-x)+abs(b-y))&1;
}
inline bool Work()
{
    int cnt=0;
    for(int i=1;i<=k;i++)
        if(xi[i]==x&&yi[i]==y) return false;
    for(int i=1;i<=k;i++)
        if(!Check(xi[i],yi[i]))
            cnt++;
    return cnt<1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k>>x>>y;
        for(int i=1;i<=k;i++) cin>>xi[i]>>yi[i];
        cout<<(Work() ? "YES" : "NO")<<endl;
    }
    return 0;
}