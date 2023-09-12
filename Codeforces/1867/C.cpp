#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int s[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i];
        static int tmp;
        int res=-1;
        for(int i=1;i<=n;i++) if(s[i]==i-1) res=i-1;
        if(res==-1) cout<<0<<endl,cout.flush(),cin>>tmp;
        else
        {
            cout<<res+1<<endl,cout.flush();
            cin>>tmp;
            while(~tmp)
            {
                cout<<tmp<<endl,cout.flush();
                cin>>tmp;
            }
        }
    }
    return 0;
}