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
const int N=1e6+10;
char a[N],b[N];
int ne[N],lena,lenb;
int main()
{
    ReadString(a+1),ReadString(b+1);
    lena=strlen(a+1),lenb=strlen(b+1);
    for(int i=2,j=0;i<=lenb;i++)
    {
        while(j&&b[i]!=b[j+1]) j=ne[j];
        if(b[i]==b[j+1]) j++;
        ne[i]=j;
    }
    for(int i=1,j=0;i<=lena;i++)
    {
        while(j&&a[i]!=b[j+1]) j=ne[j];
        if(a[i]==b[j+1]) j++;
        if(j==lenb) write(i-lenb+1),j=ne[j];
    }
    for(int i=1;i<=lenb;i++) write(ne[i],' ');
    putchar('\n');
    return 0;
}