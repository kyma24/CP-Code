#include <iostream>
#include <vector>
using namespace std;
/*
vector<int> c(101);
int mod=1e9+7;
int f(int i, int aim) {
    if(aim==0) return 1;
    if(aim<0) return 0;
    long long notTake=((i>0)?f(i-1,aim):0);
    long long take=f(i,aim-c[i]);
    return (long long)(notTake+take)%mod;
}*/
int main() {
    int mod=1e9+7;
    int n,x; cin>>n>>x;
    vector<int>c(n);
    for(int i=0; i<n; i++) cin>>c[i];

    vector<vector<int>> dp(n,vector<int>(x+1));
    for(int i=0; i<n; i++) dp[i][0]=1;
    long long notTake,take;
    for(int i=0; i<n; i++) {
        for(int aim=1; aim<=x; aim++) {
            notTake=((i>0)?dp[i-1][aim]:0);
            take=((c[i]<=aim)?dp[i][aim-c[i]]:0);
            dp[i][aim]=(long long)(notTake+take)%mod;
        }
    }
    cout<<dp[n-1][x];
}