#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
const int N=1e8+10,V=1e6+10;
int n,q;
bool np[N];
int p[V],cnt;
inline void Init()
{
    np[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(!np[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<=n;j++)
        {
            np[i*p[j]]=true;
            if(i%p[j]==0) break;
        }
    }
}
int main()
{
    n=read(),q=read();
    Init();
    for(int i=1;i<=q;i++)
    {
        int x=read();
        printf("%d\n",p[x]);
    }
    return 0;
}