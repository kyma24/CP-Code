#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N=1e5;
vector<vector<int>> adj(N+1);
vector<int> vis(N+1);

bool dfs(int i, int col) {
    if(vis[i]) {
        if(vis[i]!=col+1) return false;
        return true;
    }
    vis[i]=col+1;
    for(int j:adj[i]) if(!dfs(j,1-col)) return false;
    return true;
}

int main() {
    int M; cin>>N>>M;
    for(int a,b,i=0; i<M; i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool flag=true;
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        if(!dfs(i,0)) {
            flag=false;
            break;
        }
    }
    if(flag) for(int i=1; i<=N; i++) cout<<vis[i]<<" ";
    else cout<<"IMPOSSIBLE";
}