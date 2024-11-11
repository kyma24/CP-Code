#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// TIP: to find positive cycle that connects to a point,
// simply find nodes part of SCC's
// and in BF, if any dist is increasing in the N'th iteration,
// check if it is an SCC connected to N.

struct edge {
    int i;
    int j;
    ll x;
};

int N=2500;
vector<vector<pair<int,int>>> adj(N+1),radj(N+1);
vector<bool> vis(N+1),rvis(N+1);
// perform dfs to find if nodes part of SCC's
void dfs(int i) {
    if(vis[i]) return;
    vis[i]=true;
    for(auto j:adj[i]) dfs(j.first);
}

void rdfs(int i) {
    if(rvis[i]) return;
    rvis[i]=true;
    for(auto j:radj[i]) rdfs(j.first);
}

int main() {
    //ifstream in("susinput.txt");
    int M; cin>>N>>M;
    vector<edge> edges; edge tmp;
    while(M--) {
        int a,b; ll x; cin>>a>>b>>x;
        tmp.i=a; tmp.j=b; tmp.x=x;
        edges.push_back(tmp);
        adj[a].push_back({b,x});
        radj[b].push_back({a,x});
    }

    vector<ll> dist(N+1,-1e13);
    dist[1]=0; ll res=-1e13;
    dfs(1); rdfs(N);
    for(int i=1; i<=N; i++) {
        for(auto e:edges) {
            if(dist[e.j]<dist[e.i]+e.x) {
                dist[e.j]=dist[e.i]+e.x;
                // if last iteration, dist changes,
                // and changed node is part of SCC
                if((i==N)&&vis[e.j]&&rvis[e.j]) {
                    res=-1;
                    break;
                }
            }
        }
    }

    if(res==-1e13) res=dist[N];
    cout<<res<<endl;
}