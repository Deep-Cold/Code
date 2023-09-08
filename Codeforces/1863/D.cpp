#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=510;
int t,n,m;
char str[N][N],ans[N][N];
vector<int> row[N],col[N];
inline bool Check()
{
    for(int i=1;i<=n;i++)
    {
        if(row[i].size()&1) return false;
        for(int j=0;j<row[i].size();j+=2)
        {
            ans[i][row[i][j]]=ans[i+1][row[i][j+1]]='W';
            ans[i+1][row[i][j]]=ans[i][row[i][j+1]]='B';
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(col[i].size()&1) return false;
        for(int j=0;j<col[i].size();j+=2)
        {
            ans[col[i][j]][i]=ans[col[i][j+1]][i+1]='W';
            ans[col[i][j+1]][i]=ans[col[i][j]][i+1]='B';
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) row[i].clear();
        for(int i=1;i<=m;i++) col[i].clear();
        for(int i=1;i<=n;i++) cin>>str[i]+1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                ans[i][j]='.';
                if(str[i][j]=='L') col[j].push_back(i);
                if(str[i][j]=='U') row[i].push_back(j);
            }
        if(!Check()) cout<<"-1"<<endl;
        else
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                    cout<<ans[i][j];
                cout<<endl;
            }
        }
    }
    return 0;
}