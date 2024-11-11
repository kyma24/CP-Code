#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>dp(501,vector<int>(501));
/*
int f(int h, int l) {
    if(h==l) return 0;
    if(dp[h][l]) return dp[h][l];
    int temp=501;
    for(int i=1; i<l; i++) temp=min(temp,f(h,i)+f(h,l-i));
    for(int i=1; i<h; i++) temp=min(temp,f(i,l)+f(h-i,l));
    return dp[h][l]=temp+1;
}*/
int main() {
    int a,b; cin>>a>>b;
    //cout<<f(a,b);
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            if(i!=j) {
                dp[i][j]=501;
                for(int k=1; k<j; k++) dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                for(int k=1; k<i; k++) dp[i][j]=min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
            }
        }
    }
    cout<<dp[a][b];
}