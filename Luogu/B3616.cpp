#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int que[N],hh=1,tt;
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
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int op=read();
        if(op==1) que[++tt]=read();
        if(op==2)
        {
            if(hh>tt) puts("ERR_CANNOT_POP");
            else hh++;
        }
        if(op==3)
        {
            if(hh>tt) puts("ERR_CANNOT_QUERY");
            else printf("%d\n",que[hh]);
        }
        if(op==4) printf("%d\n",tt-hh+1);
    }
    return 0;
}