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
const int N=10010;
int n;
int h[N],in[N],e[N],ne[N],idx=1;
inline void Add(int a,int b)
{
    e[++idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    in[b]++;
}
queue<int> q;
inline void Topsort()
{
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    while(q.size())
    {
        int t=q.front();
        q.pop();
        write(t,' ');
        for(int i=h[t];i;i=ne[i])
        {
            int j=e[i];
            if(!--in[j]) q.push(j);
        }
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int v=read();
        while(v)
        {
            Add(i,v);
            v=read();
        }
    }
    Topsort();
    putchar('\n');
    return 0;
}