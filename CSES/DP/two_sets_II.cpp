#include <iostream>
#include <vector>
using namespace std;

int mod=1e9+7;
vector<vector<long long>> dp(501,vector<long long>(62626));
/*long long f(int i, int aim) {
    if(aim==0) return 1;
    if(i==1) {
        if (aim==1) return 1;
        else return 0;
    }
    if(dp[i][aim]) return dp[i][aim];
    return dp[i][aim]=((aim-i<0)?0:f(i-1,aim-i))+f(i-1,aim);
}*/

int main() {
    int n; cin>>n;
    if((n*(n+1)/2)%2!=0) cout<<0<<endl;
    else {
        int aim=n*(n+1)/4;
        //cout<<(f(n,aim)/2)%mod<<endl;
        for(int i=1; i<=n; i++) {
            dp[i][0]=1;
        }
        dp[1][1]=1;
        for(int i=1; i<=n; i++) {
            for(int a=1; a<=aim; a++) {
                dp[i][a]=(((a-i<0)?0:dp[i-1][a-i])+dp[i-1][a])%mod;
            }
        }
        cout<<dp[n][aim]<<endl;
    }
}