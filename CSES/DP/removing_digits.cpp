#include <iostream>
#include <vector>
using namespace std;
/*
int f(int curr, vector<int> &dp) {
    if(curr<0) return 1e6+1;
    if(curr==0) return 0;
    if(dp[curr]) return dp[curr];
    string s=to_string(curr);
    int mmin=1e6+1;
    for(int i=0; i<s.length(); i++) {
        if(s[i]!='0') {
            mmin=min(mmin,f(curr-(int)(s[i]-'0'),dp));
        }
    }
    return dp[curr]=mmin+1;
}*/
int main() {
    int n; cin>>n;
    vector<int> dp(n+1);
    //cout<<f(n,dp);
    dp[0]=0;
    for(int curr=1; curr<=n; curr++) {
        string s=to_string(curr);
        int mmin=1e6+1;
        for(int i=0; i<(s.length()); i++) {
            if(s[i]!='0') {
                mmin = min(mmin,dp[curr-(int)(s[i]-'0')]);
            }
        }
        dp[curr]=mmin+1;
    }
    cout<<dp[n];
}