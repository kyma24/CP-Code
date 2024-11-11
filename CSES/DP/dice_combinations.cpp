#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    int n; cin>>n;
    int mod=1e9+7;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(int i=1; i<n+1; i++) {
        for(int j=0; j<7; j++) {
            if (i-j>=0) dp[i]+=dp[i-j];
        }
        dp[i]%=mod;
    }
    cout<<dp[n]<<endl;
}