#include<bits/stdc++.h>
using namespace std;
const int N=110;
bool flag;
int t,n;
char str[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>str+1;
        flag=false;
        char ls;
        for(int i=1;i<=n;i++) 
            if(!flag) flag=true,cout<<(ls=str[i]);
            else if(ls==str[i]) flag=false;
        cout<<endl;
    }
    return 0;
}