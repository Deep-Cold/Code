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
const int N=5e5+10,K=19;
int n,m,s;
int h[N],e[N<<1],ne[N<<1],idx=1;
inline void Add(int a,int b)
{
    e[++idx]=b,ne[idx]=h[a],h[a]=idx;
}
namespace LCA
{
    int fa[N][K],dep[N];
    void Dfs(int now,int father)
    {
        fa[now][0]=father,dep[now]=dep[father]+1;
        for(int i=1;i<K&&fa[fa[now][i-1]][i-1];i++)
            fa[now][i]=fa[fa[now][i-1]][i-1];
        for(int i=h[now];i;i=ne[i])
        {
            int j=e[i];
            if(j==father) continue;
            Dfs(j,now);
        }
    }
    inline int Get_LCA(int a,int b)
    {
        if(dep[a]<dep[b]) swap(a,b);
        for(int i=K-1;i>=0;i--)
            if(dep[fa[a][i]]>=dep[b]) a=fa[a][i];
        if(a==b) return a;
        for(int i=K-1;i>=0;i--)
            if(fa[a][i]!=fa[b][i])
                a=fa[a][i],b=fa[b][i];
        return fa[a][0];
    }
}
using namespace LCA;
int main()
{
    n=read(),m=read(),s=read();
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        Add(x,y),Add(y,x);
    }
    Dfs(s,0);
    while(m--)
    {
        int a=read(),b=read();
        write(Get_LCA(a,b));
    }
    return 0;
}