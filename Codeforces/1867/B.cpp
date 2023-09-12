#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
char str[N],ans[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>str+1;
        int res=0;
        for(int i=0;i<=n;i++) ans[i]='0';
        for(int i=1;i<=n/2;i++) if(str[i]!=str[n+1-i]) res++;
        for(int i=res;i<=n;i+=2) ans[i]='1';
        if(n&1) for(int i=res+1;i<=n;i+=2) ans[i]='1';
        for(int i=(n/2-res)*2+res+2;i<=n;i++) ans[i]='0';
        ans[n+1]='\0';
        cout<<ans<<endl;
    }
    return 0;
}