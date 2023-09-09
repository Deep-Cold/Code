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
    if(x<0) putchar('-'),x=-x;
    if(!x) putchar('0');
    while(x) buf[++p]=x%10+'0',x/=10;
    while(~p) putchar(buf[p--]);
    putchar(ch);
}
const int N=1e4+10;
namespace UnionFind
{
    int a[N],fa[N];
    int Find(int x)
    {
        return fa[x]==x ? fa[x] : fa[x]=Find(fa[x]);
    }
    inline void Merge(int x,int y)
    {
        fa[Find(x)]=Find(y);
    }
    inline bool Search(int x,int y)
    {
        return Find(x)==Find(y);
    }
}
using namespace UnionFind;
int n,m;
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++) fa[i]=i;
    while(m--)
    {
        int z=read(),x=read(),y=read();
        if(z==1) Merge(x,y);
        if(z==2) puts(Search(x,y)?"Y":"N");
    }
    return 0;
}