#include <iostream>
#include <vector>
using namespace std;
int n,m,mod=1e9+7;
vector<vector<int>> dp(1e5,vector<int>(101,0));
vector<int> x(1e5);
/*
int f(int i, int v) {
    if(i==0) {
        if(x[0]==0) return 1;
        else if(x[0]==v) return 1;
        else return 0;
    }
    if(dp[i][v]) return dp[i][v];
    if(x[i]==0) {
        for(int k:{v-1,v,v+1}) {
            if(k>=1&&k<=m) {
                dp[i][v]+=f(i-1,k);
                dp[i][v]%=mod;
            }
        }
    } else {
        if(x[i]!=v) return 0;
        for(int k:{v-1,v,v+1}) {
            if(k>=1&&k<=m) {
                dp[i][v]+=f(i-1,k);
                dp[i][v]%=mod;
            }
        }
    }
    return dp[i][v];
}*/

int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>x[i];

    if(x[0]==0) {
        for(int i=1; i<=m; i++) dp[0][i]=1;
    } else {
        dp[0][x[0]]=1;
    }

    for(int i=1; i<n; i++) {
        if(x[i]==0) {
            for(int v=1; v<=m; v++) {
                for(int k:{v-1,v,v+1}) {
                    if(k>=1&&k<=m) {
                        dp[i][v]+=dp[i-1][k];
                        dp[i][v]%=mod;
                    }
                }
            }
        } else {
            for(int k:{x[i]-1,x[i],x[i]+1}) {
                if(k>=1&&k<=m) {
                    dp[i][x[i]]+=dp[i-1][k];
                    dp[i][x[i]]%=mod;
                }
            }
        }
    }
    int res=0;
    for(int i=1; i<=m; i++) {
        res+=dp[n-1][i];
        res%=mod;
    }
    cout<<res<<endl;
}