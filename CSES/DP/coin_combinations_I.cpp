#include <iostream>
#include <vector>
using namespace std;

int main() {
    int mod=1e9+7;
    int n; cin>>n;
    int x; cin>>x;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin>>c[i];
    vector<long long> dp(x+1);
    dp[0]=1;
    for(int i=1; i<=x; i++) {
        for(auto coin:c) {
             if(i-coin>=0) dp[i]+=dp[i-coin];
        }
        dp[i]%=mod;
    }
    cout<<dp[x]<<endl;
}