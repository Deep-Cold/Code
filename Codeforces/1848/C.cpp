#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int a[N],b[N];
int Count(int a,int b)
{
    if(a==0) return 0;
    if(b==0) return 1;
    if(a>b)
    {
        int k=a/b,u=k/2;
        if(u>0) return Count(a-u*2*b,b);
        return Count(b,a-b)+1;
    }
    else if(a<b) return Count(b,b-a)+1;
    else return 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        int odd=0,even=0,news=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0&&b[i]==0) continue;
            int x=Count(a[i],b[i])%3;
            if(x==0) odd++; 
            else if(x==1) even++;
            else if(x==2) news++;
        }
        int res=0;
        if(odd) res++;
        if(even) res++;
        if(news) res++;
        if(res<=1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}