#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<vector<int>> vvi;

void dfs(int i, int p, vvi&adj, vector<bool>&vis) {
    vis[i]=1;
    for(int j:adj[i]) {
        if(j==p) continue;
        dfs(j,i,adj,vis);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;
    vvi adj(N+1);
    for(int i=1; i<=N; i++) {
        int p; cin>>p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    vector<bool> vis(N+1);
    int res=0;
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        dfs(i,0,adj,vis);
        res++;
    }

    cout<<res<<endl;
}