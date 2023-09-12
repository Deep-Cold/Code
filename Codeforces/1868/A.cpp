#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,m;
int str[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    str[0]=1,str[1]=0;
    for(int i=2;i<N;i++) str[i]=i;
    while(t--)
    {
        cin>>n>>m;
        int ans= m==1 ? 0 : min(m,n+1);
        cout<<ans<<endl;
        if(ans==0)
            for(int i=1;i<=n;i++) cout<<"0"<<endl;
        else if(ans==m)
        {
            for(int i=0;i<m-1;i++)
            {
                for(int j=0;j<m;j++)
                    cout<<str[(j-i+m)%m]<<' ';
                cout<<endl;
            }
            for(int i=m-1;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cout<<str[j]<<' ';
                cout<<endl;
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n+1;j++)
                    cout<<str[(j-i+n+1)%(n+1)]<<' ';
                for(int j=n+1;j<m;j++)
                    cout<<j<<' ';
                cout<<endl;
            }
        }
    }
    return 0;
}