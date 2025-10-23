#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

// root: finds lowest {depth, node #}
pair<int,int> root(int i, int p, int d, vector<vector<int>>&adj) {
    pair<int,int> ret={d,i},cur;
    for(int j:adj[i]) {
        if(j==p) continue;
        cur=root(j,i,d+1,adj);
        if(cur.first>ret.first) ret=cur;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int T; cin>>T;

    int res=0;
    while(T--) {
        int N; cin>>N;

        vector<vector<int>> adj(N+1);
        for(int i=1; i<N; i++) {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        res+=root(root(1,0,0,adj).second,0,0,adj).first;
    }

    cout<<res<<endl;
}