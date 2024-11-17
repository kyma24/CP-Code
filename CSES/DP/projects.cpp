#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin>>n;
    map<int,int> compress;
    vector<int> a(n),b(n),p(n);
    for(int i=0; i<n; i++) {
        cin>>a[i]>>b[i]>>p[i];
        b[i]++;
        compress[a[i]], compress[b[i]];
    }

    // assigns coordinate values to items in map(sorted)
    int coords=0;
    for(auto&v:compress) {
        v.second=coords++;
    }

    // assign values of start and weight to ending coordinate
    vector<vector<pair<int,int>>> project(coords);
    for(int i=0; i<n; i++) {
        project[compress[b[i]]].emplace_back(compress[a[i]],p[i]);
    }
    vector<long long> dp(coords,0);
    for(int i=0; i< oords; i++) {
        if(i>0) dp[i]=dp[i-1];
        for(auto p:project[i]) {
            dp[i]=max(dp[i],dp[p.first]+p.second);
        }
    }
    cout<<dp[coords-1]<<endl;
}
