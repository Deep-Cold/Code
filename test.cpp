#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int N=2e5+10;
int n,m;
int a[N];
namespace SegmentTree
{
    struct node
    {
        ll sum,tag,len;
        #define sum(x) unit[(x)].sum
        #define tag(x) unit[(x)].tag
        #define len(x) unit[(x)].len    
    }unit[N<<2];
    #define lson(x) ((x)<<1)
    #define rson(x) ((x)<<1|1)
    inline void Push_up(int k)
    {
        sum(k)=sum(lson(k))+sum(rson(k));
    }
    inline void Push_tag(int k,ll val)
    {
        tag(k)+=val,sum(k)+=len(k)*val;
    }
    inline void Push_down(int k)
    {
        if(tag(k)) Push_tag(lson(k),tag(k)),Push_tag(rson(k),tag(k)),tag(k)=0;
    }
    void Build(int k,int l,int r)
    {
        len(k)=r-l+1;
        if(l==r) return sum(k)=a[l],void();
        int mid=l+r>>1;
        Build(lson(k),l,mid),Build(rson(k),mid+1,r);
        Push_up(k);
    }
    void Update(int k,int l,int r,int L,int R,ll val)
    {
        if(L<=l&&R>=r) return Push_tag(k,val);
        Push_down(k);
        int mid=l+r>>1;
        if(L<=mid) Update(lson(k),l,mid,L,R,val);
        if(R>mid) Update(rson(k),mid+1,r,L,R,val);
        Push_up(k);
    }
    ll Query(int k,int l,int r,int L,int R)
    {
        if(L<=l&&R>=r) return sum(k);
        Push_down(k);
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid) ans+=Query(lson(k),l,mid,L,R);
        if(R>mid) ans+=Query(rson(k),mid+1,r,L,R);
        Push_up(k);
        return ans;
    }
}
int main()
{
    return 0;
}