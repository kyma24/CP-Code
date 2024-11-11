#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp(5001,vector<int>(5001));
/*
int f(int i, int j, string &A, string &B) {
    if(i==0) return j;
    if(j==0) return i;
    if(dp[i][j]) return dp[i][j];
    if(A[i-1]==B[j-1]) return dp[i][j]=f(i-1,j-1,A,B);
    return dp[i][j]=1+min(f(i-1,j,A,B),min(f(i,j-1,A,B),f(i-1,j-1,A,B)));
}*/
int main() {
    string s1,s2; cin>>s1>>s2;
    int n; n=s1.length();
    int m; m=s2.length();
    //cout<<f(n,m,s1,s2);
    for(int i=0; i<=n; i++) {
        dp[i][0]=i;
    } for(int j=0; j<=m; j++) {
        dp[0][j]=j;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    cout<<dp[n][m];
}