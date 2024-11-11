#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// suppose coupon is used on edge A->B
// min route would be min(1->A)+(AB/2)+min(B->N)

void dij(ll s,vector<ll>&dist,vector<bool>&vis,vector<vector<pair<ll,ll>>>&adj) {
    ll i; pair<ll,ll> cur;
    priority_queue<pair<ll,ll>> q; q.push({0,s});
    while(!q.empty()) {
        cur=q.top(); q.pop();
        i=cur.second;
        if(vis[i]) continue;
        vis[i]=true;
        for(auto j:adj[i]) {
            if(dist[i]+j.second<dist[j.first]) {
                dist[j.first]=dist[i]+j.second;
                q.push({-dist[j.first],j.first});
            }
        }
    }
}

int main() {
    int N,M; cin>>N>>M;
    // adj[a]: b,c where edge of weight c from a -> b
    vector<vector<pair<ll,ll>>> adj(N+1),radj(N+1);
    vector<vector<ll>> edges;
    for(ll a,b,c,i=0; i<M; i++) {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        radj[b].push_back({a,c});
        edges.push_back({a,b,c});
    }

    // dijkstra's
    vector<ll> from1(N+1,1e15),toN(N+1,1e15);
    from1[1]=0; toN[N]=0;
    vector<bool> vis(N+1);
    dij(1,from1,vis,adj); 
    fill(vis.begin(),vis.end(),false);
    dij(N,toN,vis,radj);

    ll a,b,c,res=1e15;
    // for every edge
    for(auto e:edges) {
        a=e[0]; b=e[1]; c=e[2];
        res=min(res,from1[a]+(int)(c/2)+toN[b]);
    }

    cout<<res<<endl;
}