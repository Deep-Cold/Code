#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,p[N],pos[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i],pos[p[i]]=i;
        for(int i=1;i<n;i++) if(pos[i]>pos[i+1]) ans++;
        cout<<ans<<endl;
    }
    return 0;
}