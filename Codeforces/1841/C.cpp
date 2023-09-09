#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n;
char str[N];
int dp[N][5][2];
int num[]={1,10,100,1000,10000};
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>str+1;
        n=strlen(str+1);
        for(int i=1;i<=n;i++)
            for(int j=0;j<5;j++)
                for(int k=0;k<2;k++)
                    dp[i][j][k]=INT_MIN;
        for(int j=0;j<5;j++)
            for(int k=0;k<2;k++)
                dp[n+1][j][k]=0;
        for(int i=n;i>=1;i--)
            for(int j=0;j<5;j++)
            {
                int k=max(j,str[i]-'A');
                if(k>str[i]-'A')
                {
                    if(dp[i+1][j][0]!=INT_MIN) dp[i][k][0]=max(dp[i][k][0],dp[i+1][j][0]-num[str[i]-'A']);
                    if(dp[i+1][j][1]!=INT_MIN) dp[i][k][1]=max(dp[i][k][1],dp[i+1][j][1]-num[str[i]-'A']);
                }
                else
                {
                    if(dp[i+1][j][0]!=INT_MIN) dp[i][k][0]=max(dp[i][k][0],dp[i+1][j][0]+num[str[i]-'A']);
                    if(dp[i+1][j][1]!=INT_MIN) dp[i][k][1]=max(dp[i][k][1],dp[i+1][j][1]+num[str[i]-'A']);
                }
                if(dp[i+1][j][0]==INT_MIN) continue;
                for(int u=0;u<5;u++)
                    if(u<j) dp[i][j][1]=max(dp[i][j][1],dp[i+1][j][0]-num[u]);
                    else dp[i][u][1]=max(dp[i][u][1],dp[i+1][j][0]+num[u]);
            }
        int ans=INT_MIN;
        for(int j=0;j<5;j++)
            for(int k=0;k<2;k++)
                ans=max(ans,dp[1][j][k]);
        cout<<ans<<endl;
    }
    return 0;
}