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
inline char ReadChar()
{
    static char ch;
    while(isspace(ch=getchar()));
    return ch;
}
inline void ReadString(char *buf)
{
    while(isspace(*buf=getchar()));
    while(!isspace(*++buf=getchar()));
    *buf='\0';
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
const int N=2010,M=1.5e5+10;
int h[N],e[M],ne[M],w[M],idx=1;
int dis[N],cnt[N],T;
bool inq[N];
int n,m,a,b,c;
queue<int> q;
inline void Clear()
{
    memset(dis,0X3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    memset(inq,false,sizeof inq);
    memset(h,0,sizeof(h)),idx=1;
}
inline void Add(int a,int b,int c)
{
    e[++idx]=b,ne[idx]=h[a],h[a]=idx,w[idx]=c;
}
inline bool Spfa()
{
    q.push(1),inq[1]=true,dis[1]=0;
    while(q.size())
    {
        int t=q.front();q.pop();
        inq[t]=false;
        for(int i=h[t];i;i=ne[i])
        {
            int j=e[i];
            if(dis[j]>dis[t]+w[i])
            {
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return true;
                if(!inq[j]) q.push(j),inq[j]=true;
            }
        }
    }
    return false;
}
int main()
{
    T=read();
    while(T--)
    {
        Clear();
        n=read(),m=read();
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            a=read(),b=read(),c=read();
            Add(a,b,c);
            if(c>=0) Add(b,a,c);
        }
        puts(Spfa() ? "YES" : "NO");
    }
    return 0;
}