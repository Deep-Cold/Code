#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef unsigned long long ull;
int T,n;
ull stk[N];
int top;
char ch[10];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n),top=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",ch);
            if(!strcmp(ch,"push"))
            {
                static ull x;
                scanf("%llu",&x);
                stk[++top]=x;
            } 
            else if(!strcmp(ch,"pop"))
            {
                if(!top) puts("Empty");
                else top--;
            }
            else if(!strcmp(ch,"query"))
            {
                if(!top) puts("Anguei!");
                else printf("%llu\n",stk[top]);
            }
            else printf("%d\n",top);
        }
    }
    return 0;
}