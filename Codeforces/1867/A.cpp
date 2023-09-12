#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=4e4+10;
int t,n;
PII a[N];
int b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
        sort(a+1,a+n+1,greater<PII>());
        for(int i=1;i<=n;i++) b[a[i].second]=i;
        for(int i=1;i<=n;i++) cout<<b[i]<<' ';
        cout<<endl;
    }
    return 0;
}