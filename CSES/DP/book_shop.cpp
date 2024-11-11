#include <iostream>
#include <vector>
using namespace std;
/*
vector<int> h(1000),s(1000);
vector<vector<int>> dp(1000,vector<int>(100001,0));
int f(int ind, int w) {
    if(ind==0) {
        if (h[0]<=w) return s[0];
        return 0;
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notTake=f(ind-1,w);
    int take=INT_MIN;
    if(h[ind]<=w) take=s[ind]+f(ind-1,w-h[ind]);
    return dp[ind][w]=max(notTake,take);
}*/
int main() {
    int n,x; cin>>n>>x;
    vector<int>h(n),s(n);
    vector<int>dp(x+1);
    for(int i=0; i<n; i++) cin>>h[i];
    for(int i=0; i<n; i++) cin>>s[i];
    // base case
    for(int i=0; i<=x; i++) {
        if(h[0]<=i) dp[i]=s[0];
    }
    // construct dp array
    for(int i=1; i<n; i++) {
        for(int w=x; w>=0; w--) {
            dp[w]=max(dp[w],((h[i]<=w)?s[i]+dp[w-h[i]]:0));
        }
    }
    cout<<dp[x];
}