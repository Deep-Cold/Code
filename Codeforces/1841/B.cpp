#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,q,x[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>q;
        bool flag=false;
        for(int i=1;i<=q;i++) cin>>x[i];
        int ls=0,fir=x[1];
        for(int i=1;i<=q;i++)
        {
            if((x[i]>=ls&&!flag)||(flag&&x[i]>=ls&&x[i]<=fir)) ls=x[i],cout<<1;
            else if(flag==false&&x[i]<=fir) flag=true,ls=x[i],cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
    return 0;
}