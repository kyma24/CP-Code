#include <iostream>
#include <vector>
using namespace std;
vector<int> x(5000);
vector<vector<long long>> dp(5000,vector<long long>(5000));
/*
long long f(int l, int r) {
    if (l==r) return x[l];
    if(dp[l][r]) return dp[l][r];
    return dp[l][r]=max((long long)(x[l]-f(l+1,r)), (long long)(x[r]-f(l,r-1)));
}*/
int main() {
    int n; cin>>n;
    long long sum=0;
    for(int i=0; i<n; i++) {
        cin>>x[i];
        sum+=x[i];
    }
    /*
    long long res=f(0,n-1);
    cout<<(long long)(sum+res)/2<<endl;*/
    for(int l=n-1; l>=0; l--) {
        for(int r=l; r<n; r++) {
            if(l==r) dp[l][r]=x[l];
            else dp[l][r]=max(x[l]-dp[l+1][r],x[r]-dp[l][r-1]);
        }
    }
    cout<<(sum+dp[0][n-1])/2<<endl;
}