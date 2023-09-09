#include<bits/stdc++.h>
using namespace std;
int t,b,c,h;
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>b>>c>>h;
        cout<<min(b*2-1,(c+h)*2+1)<<endl;
    }
    return 0;
}