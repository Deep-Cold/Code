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
const int Mod=1e9+7;
inline int Add(int a,int b)
{
    if(a+b>Mod) return a+b-Mod;
    if(a+b<0) return a+b+Mod;
    return a+b;
}
struct Matrix
{
    int w[5][5];
    int row,col;
    Matrix()
    {
        memset(w,0,sizeof(w));
    }
    inline void Init(int r,int c,bool type)
    {
        row=r,col=c;
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                w[i][j]= i==j ? type : 0;
    }
    inline Matrix operator*(const Matrix &t) const
    {
        Matrix ans;
        ans.Init(row,t.row,0);
        for(int i=1;i<=ans.row;i++)
            for(int j=1;j<=ans.col;j++)
                for(int k=1;k<=col;k++)
                    ans.w[i][j]=Add(ans.w[i][j],1ll*w[i][k]*t.w[k][j]%Mod);
        return ans;
    }
};
inline Matrix operator^( Matrix t,int k)
{
    Matrix ans;
    ans.Init(t.row,t.col,1);
    while(k)
    {
        if(k&1) ans=ans*t;
        t=t*t;
        k>>=1;
    }
    return ans;
}
Matrix a,t;
int T,n;
int main()
{
    T=read();
    while(T--)
    {
        a.row=1,a.col=3,a.w[1][1]=a.w[1][2]=a.w[1][3]=1;
        t.Init(3,3,0),t.w[2][1]=t.w[3][2]=t.w[1][3]=t.w[3][3]=1;
        n=read()-1;
        write((a*(t^n)).w[1][1]);
    }
    return 0;
}