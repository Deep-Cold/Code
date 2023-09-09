#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=3e5+10;
int t,n,k;
PII a[N];
inline bool Cmp(PII a,PII b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;    
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i].first;
        for(int i=1;i<=n;i++)
        {
            if(a[i].first%k==0) a[i].first=k;
            else a[i].first%=k;
        }
        for(int i=1;i<=n;i++) a[i].second=i;
        sort(a+1,a+n+1,Cmp);
        for(int i=1;i<=n;i++) cout<<a[i].second<<' ';
        cout<<endl;
    }
    return 0;
}