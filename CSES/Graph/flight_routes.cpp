#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll = pair<ll,ll>;

// MODIFICATION OF DIJKSTRA'S
// BFS, keep track of K shortest path costs

// for each child, if we can update its kth smallest distance from 1,
// we do so, and push it into the queue to update its children
// with the new cost.

int N=1e5;
vector<vector<pll>> adj(N+1);

int main() {
    int M,K; cin>>N>>M>>K;
    for(int a,b,c,i=0; i<M; i++) {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    
    // track min K dists from node 1 to each node.
    vector<vector<ll>> dist_from_1(N+1,vector<ll>(K,1e15));
    dist_from_1[1][0]=0;

    priority_queue<pll> q; q.push({0,1});
    pll tmp; ll curdist,i,j,w;
    while(!q.empty()) {
        tmp=q.top(); q.pop();
        curdist=-tmp.first; i=tmp.second;
        // if we have already found a better Kth shortest dist before processing this node
        if(curdist>dist_from_1[i][K-1]) continue;
        for(auto e:adj[i]) {
            j=e.first; w=e.second;
            // curdist + edge weight < kth smallest dist of j
            if(curdist+w<dist_from_1[j][K-1]) {
                dist_from_1[j][K-1]=curdist+w;
                sort(dist_from_1[j].begin(),dist_from_1[j].end());
                q.push({-(curdist+w),j});
            }
        }
    }

    for(auto v:dist_from_1[N]) cout<<v<<" ";
}