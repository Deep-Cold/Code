#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef pair<int,int> PII;
typedef long long ll;
int t,n;
int p[N];
ll ans[N];
PII num[N];
set<int> s,sm;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) num[i].first=p[i],num[i].second=i;
    sort(num+1,num+n+1);
    ll ans=0;
    s.insert(n+1);
    for(int i=1;i<=n+1;i++) sm.insert(i);
    for(int i=1;i<=n;i++)
    {
        int pos=*s.lower_bound(num[i].second);
        sm.erase(num[i].second);
        int pp=*sm.lower_bound(num[i].second);
        ans+=pos-num[i].second-1;
        if(pp>pos)
        {
            int pos2=*s.lower_bound(pos);
            if(pos2!=n+1)
            {
                int pos3=*s.lower_bound(pos2);
                ans+=pos3-pos2+1;
            }
        }
        s.insert(num[i].second);
        cout<<ans<<' ';
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}