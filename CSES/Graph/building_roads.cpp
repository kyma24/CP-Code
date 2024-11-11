#include <bits/stdc++.h>
using namespace std;

// find the connected components
// required roads=cc-1
// pick 2 points from each pair of ccs
int n=1e5;
vector<vector<int>> adj(n+1);
vector<int> vis(n+1);
void dfs(int i) {
    if(vis[i]) return;
    vis[i]=1;
    for(int nxt:adj[i]) dfs(nxt);
}
int main() {
    int m; cin>>n>>m;
    for(int a,b,i=0; i<m; i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>res;
    int count=0;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i);
            res.push_back(i);
            count++;
        }
    }
    cout<<count-1<<endl;
    for(int i=0; i<res.size()-1; i++) cout<<res[i]<<" "<<res[i+1]<<endl;
}