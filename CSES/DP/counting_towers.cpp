#include <iostream>
#include <vector>
using namespace std;
/*
vector<vector<long long>>dp(2,vector<long long>(1e6+1,0));
long long a,b,mod=1e9+7;
int f(int type, int h) {
    if(h==1) return 1;
    if(dp[type][h]) return dp[type][h];
    a=f(0,h-1); b=f(1,h-1);
    if(type==0) return dp[0][h]=(((4*a)+b)%mod);
    else return dp[1][h]=((a+(2*b))%mod);
}
*/
int main() {
    int t,n; cin>>t;
    int mod=1e9+7;
    vector<vector<long long>>dp(2,vector<long long>(1e6+1,0));
    dp[0][1]=dp[1][1]=1;
    for(int _=0; _<t; _++) {
        cin>>n;
        /*dp=vector<vector<int>>(2,vector<int>(n+1,-1));
        cout<<(f(0,n)+f(1,n))%mod<<endl;*/
        if(dp[0][n]&&dp[1][n]) cout<<(dp[0][n]+dp[1][n])%mod<<endl;
        else {
            for(int i=2; i<=n; i++) {
                if(dp[0][i]&&dp[1][i]) continue;
                dp[0][i]=(((4*dp[0][i-1])%mod+dp[1][i-1])%mod);
                dp[1][i]=((dp[0][i-1]+2*dp[1][i-1]%mod)%mod);
            }
            cout<<(dp[0][n]+dp[1][n])%mod<<endl;
            //cout<<dp[0][n]<<" "<<dp[1][n]<<endl;
        }
    }
}