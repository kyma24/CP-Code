#include <iostream>
#include <vector>
using namespace std;
vector<int>x(2*1e5);
// Top-Down: too much memory
/*vector<vector<int>>dp(2*1e5,vector<int>(2*1e5));
int f(int i, int prev) {
    if(i==0) {
        if(x[0]<x[prev]) return 1;
        else return 0;
    }
    if(dp[i][prev]) return dp[i][prev];
    return dp[i][prev]=max(f(i-1,prev),((x[i]<x[prev])?f(i-1,i)+1:0));
}*/
// Bottom-Up: allows for 1D DP
/*
vector<int> dp(2*1e5+1,1);
int n;
int f(int i, int prev) {
    if(i>=n) return 0;
    if(dp[prev+1]) return dp[prev+1];
    int take=0;
    if(prev==-1||x[i]>x[prev]) take=f(i+1,i)+1;
    return dp[prev+1]=max(f(i+1,prev),take);
}*/

int main() {
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>x[i];
    // Tabulation
    /*
    dp[0]=1;
    int res=0;
    for(int i=0; i<n; i++) {
        for(int prev=0; prev<=i; prev++) {
            dp[i]=max(dp[i],((x[i]>x[prev])?dp[prev]+1:0));
        }
        res=max(res,dp[i]);
    }
    cout<<res<<endl;*/
    vector<int> dp;
    for(int i=0; i<n; i++) {
        auto it=lower_bound(dp.begin(),dp.end(),x[i]);
        if(it==dp.end()) dp.push_back(x[i]);
        else dp[it-dp.begin()]=x[i];
    }
    cout<<dp.size()<<endl;
}