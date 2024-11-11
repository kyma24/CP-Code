#include <iostream>
#include <vector>
using namespace std;

int main() {
    int mod=1e9+7;
    int n; cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }
    vector<vector<long long>> dp(n,vector<long long>(n,0));
    for(int i=0; i<n; i++) {
        dp[i][n-1]=((grid[i][n-1]=='*')?0:1);
        dp[n-1][i]=((grid[n-1][i]=='*')?0:1);
    }
    for(int i=n-2; i>=0; i--) {
        if (dp[i+1][n-1]==0) dp[i][n-1]=0;
        if (dp[n-1][i+1]==0) dp[n-1][i]=0;
    }

    if(grid[0][0]=='*'||grid[n-1][n-1]=='*') cout<<0<<endl;
    else {
        for(int i=n-2; i>=0; i--) {
            for(int j=n-2; j>=0; j--) {
                if(grid[i][j]!='*') {
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
                    dp[i][j]%=mod;
                }
            }
        }
        cout<<dp[0][0]<<endl;
    }
}