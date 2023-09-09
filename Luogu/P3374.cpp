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
const int N=5e5+10;
int n,m;
namespace BIT
{
    int unit[N];
    #define lowbit(x) ((x)&-(x))
    inline void Add(int x,int v)
    {
        for(;x<=n;x+=lowbit(x)) unit[x]+=v;
    }
    inline int Ask(int x)
    {
        int res=0;
        for(;x;x-=lowbit(x)) res+=unit[x];
        return res;
    }
    inline int Ask(int l,int r)
    {
        return Ask(r)-Ask(l-1);
    }
}
using namespace BIT;
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++) Add(i,read()); 
    while(m--)
    {
        int op=read(),x=read(),y=read();
        if(op==1) Add(x,y);
        if(op==2) write(Ask(x,y));
    }
    return 0;
}