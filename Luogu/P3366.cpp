#include<bits/stdc++.h>
using namespace std;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
static char buf[1<<20],*p1=buf,*p2=buf;
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
template<typename T>
inline void write(T x,char ch='\n')
{
    static char buf[20];
    int p=-1;
    if(!x) putchar('0'); 
    if(x<0) putchar('-'),x=-x;
    while(x) buf[++p]=x%10+'0',x/=10;
    while(~p) putchar(buf[p--]);
    putchar(ch);
}
const int N=5010,M=2e5+10;
int n,m;
namespace UnionFind
{
    int fa[N];
    int Find(int x)
    {
        return fa[x]==x ? x : fa[x]=Find(fa[x]);
    }
    inline void Merge(int x,int y)
    {
        fa[x]=y;
    }
    inline bool Search(int x,int y)
    {
        return Find(x)==Find(y);
    }
}
using namespace UnionFind;
namespace Kruskal
{
    struct Edge
    {
        int u,v,w;
        inline bool operator<(const Edge &t) const
        {
            return w<t.w;
        }
    }a[M];
    inline int Work()
    {
        int cnt=0,ans=0;
        sort(a+1,a+m+1);
        for(int i=1;i<=m;i++)
        {
            if(Search(a[i].u,a[i].v)) continue;
            ans+=a[i].w,Merge(Find(a[i].u),Find(a[i].v)),cnt++;
            if(cnt==n-1) break;
        }
        return cnt==n-1 ? ans : -1;
    }
}
using namespace Kruskal;
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].w=read();
    for(int i=1;i<=n;i++) fa[i]=i;
    int ans=Work();
    if(~ans) write(ans);
    else puts("orz");
    return 0;
}