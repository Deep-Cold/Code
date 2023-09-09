#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N],m;
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cin>>m;
        int ans=0;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
            if(m>(n-a[i])) ans+=n-a[i]-1,m-=n-a[i];
            else
            {
                ans+=m-1;
                break;
            }
        cout<<ans<<endl;
    }
    return 0;
}