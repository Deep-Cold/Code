#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int t,n;
char str1[N],str2[N];
inline bool Check()
{
    for(int i=1;i<n;i++) if(str1[i]=='0'&&str2[i]=='0'&&str1[i+1]=='1'&&str2[i+1]=='1') return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>str1+1>>str2+1;
        n=strlen(str1+1);
        if(Check()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}