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
    if(x<0) x=-x,putchar('-');
    while(x) buf[++p]=x%10+'0',x/=10;
    while(~p) putchar(buf[p--]);
    putchar(ch);
}
int main()
{
    write(read()),write(read()),write(read());
    return 0;
}