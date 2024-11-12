#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//dijkstra's

int main() {
    int N,M; cin>>N>>M;
    vector<vector<pair<ll,ll>>> adj(N+1);
    while(M--) {
        int a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    vector<bool> vis(N+1); vector<ll> dist(N+1,2e14+1);
    // first: neg weight. second: from city number
    priority_queue<pair<ll,ll>> q; q.push({0,1});
    dist[1]=0;
    while(!q.empty()) {
        int i=q.top().second;q.pop();
        if(vis[i]) continue;
        vis[i]=true;

        for(auto p:adj[i]) {
            int j=p.first,w=p.second;
            if(dist[i]+w<dist[j]) {
                dist[j]=dist[i]+w;
                q.push({-dist[j],j});
            }
        }
    }

    for(int i=1; i<=N; i++) cout<<dist[i]<<" ";
}
