#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef pair<int,int> PII;
int t,n,m;
char str[N];
int num[N];
PII a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>str+1;
        for(int i=1;i<=n;i++) num[i]=str[i]-'0'+num[i-1];
        for(int i=1;i<=m;i++) cin>>a[i].first>>a[i].second;
        sort(a+1,a+m+1);
        int num0=0,num1=0,l=a[1].first,r=a[1].second,ans=1;
        for(int i=a[1].first;i<=a[1].second;i++)
        {
            if(str[i]=='0') num0++;
            else num1++;
        }
        for(int i=2;i<=m;i++)
        {
            bool flag=false;

        }
        cout<<ans<<endl;
    }
    return 0;
}