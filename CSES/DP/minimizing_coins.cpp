#include <iostream>
#include <vector>
using namespace std;

int main() {
    int mmax=1e6+1;
    int n; cin>>n;
    int x; cin>>x;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin>>c[i];
    vector<int> dp(x+1,mmax);
    dp[0]=0;
    for(int i=1; i<=x; i++) {
        for(auto j:c) {
            if(i-j>=0) dp[i]=min(dp[i],dp[i-j]+1);
        }
    }
    cout<<((dp[x]!=mmax)?dp[x]:-1)<<endl;
}