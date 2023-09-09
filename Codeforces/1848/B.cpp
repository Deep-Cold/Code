#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,k;
int c[N];
vector<int> seq[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>c[i];
        for(int i=1;i<=n;i++) seq[c[i]].push_back(i);
        int ans=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int maxn=INT_MIN,secn=INT_MIN;
            for(int j=0;j<seq[i].size();j++)
            {
                if(j==0) maxn=seq[i][j]-1;
                if(j!=seq[i].size()-1)
                {
                    int num=seq[i][j+1]-seq[i][j]-1;
                    if(num>=maxn) secn=maxn,maxn=num;
                    else if(num>secn) secn=num;
                }
                else
                {
                    int num=n-seq[i][j];
                    if(num>=maxn) secn=maxn,maxn=num;
                    else if(num>secn) secn=num;
                }
            }
            if(maxn/2<secn) ans=min(ans,secn);
            else if(maxn>=0) ans=min(ans,maxn/2);
        }
        for(int i=1;i<=k;i++) seq[i].clear();
        cout<<ans<<endl;
    }
    return 0;
}