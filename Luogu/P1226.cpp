#include<bits/stdc++.h>
using namespace std;
int a,b,p;
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
inline int Qpow(int a,int b,int p)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1ll*res*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return res;
}
int main()
{
    a=read(),b=read(),p=read();
    printf("%d^%d mod %d=%d\n",a,b,p,Qpow(a,b,p));
    return 0;
}