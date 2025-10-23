#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=100;

vector<pair<int,int>> adj[maxN];
int maxCost(int i, int p) {
    int j,w,maxCh=0;
    for(auto x:adj[i]) {
        tie(j,w)=x;
        if(j==p) continue;
        maxCh=max(maxCh,w+maxCost(j,i));
    }
    return maxCh;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;

    int u,v,c;
    for(int i=1; i<N; i++) {
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    cout<<maxCost(0,0)<<endl;
}