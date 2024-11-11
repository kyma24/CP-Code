#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp(100,vector<int>(1e5+1));
vector<int> c(100);
int f(int i, int x) {
    if(i==0) {
        if(x==c[0] || x==0) return 1;
        else return 0;
    }
    if(x<0) return 0;
    if(dp[i][x]) return dp[i][x];
    return dp[i][x]=(f(i-1,x-c[i]) || f(i-1,x));
}

int main() {
    int n; cin>>n;
    int s = 0;
    for(int i=0; i<n; i++) {
        cin>>c[i];
        s+=c[i];
        dp[i][0]=1;
    }
    dp[0][c[0]]=1;
    for(int i=1; i<n; i++) {
        for(int x=1; x<=s; x++) {
            if(x-c[i]>=0) {
                dp[i][x]=(dp[i-1][x-c[i]]||dp[i-1][x]);
            } else {
                dp[i][x]=dp[i-1][x];
            }
        }
    }
    int count=0;
    vector<int> res;
    for(int i=s; i>0; i--) {
        if(dp[n-1][i]) {
            count++;
            res.push_back(i);
        }
    }
    cout<<res.size()<<endl;
    for(int i=res.size()-1; i>=0; i--) {
        cout<<res[i]<<" ";
    }
}