#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,n,a,q;
char str[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>q>>str+1;
        int nump=0,cnt=0;
        bool flag=false;
        if(n==a) flag=true;
        for(int i=1;i<=q;i++)
        {
            if(str[i]=='+') nump++,cnt++;
            else cnt--;
            if(a+cnt>=n) flag=true;
        }
        if(flag) puts("YES");
        else if(nump+a>=n) puts("MAYBE");
        else puts("NO");
    }
    return 0;
}