#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n>4) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}