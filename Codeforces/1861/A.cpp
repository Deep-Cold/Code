#include<bits/stdc++.h>
using namespace std;
int t;
char str[10];
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>str+1;
        for(int i=1;i<=9;i++)
            if(str[i]=='1')
            {
                cout<<"13"<<endl;
                break;
            }
            else if(str[i]=='3')
            {
                cout<<"31"<<endl;
                break;
            }
    }
    return 0;
}