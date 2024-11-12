#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// simply construct graph, putting a as parent of b
// then take topo sort, guarantees a is before b if no cycle

const int maxN=1e5;
int vis[maxN+1];
vector<int> res,adj[maxN+1];
bool topo(int i) {
    if(vis[i]==1) return false;
    if(vis[i]==2) return true;
    vis[i]=1;
    for(int j:adj[i]) if(!topo(j)) return false;
    vis[i]=2; res.push_back(i);
    return true;
}

int main() {
    int N,M; cin>>N>>M;
    int a,b;
    while(M--) {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    bool flag=true;
    for(int i=1; i<=N; i++) {
        if(vis[i]==2) continue;
        flag=flag&&topo(i);
        if(!flag) break;
    }

    if(flag) for(int i=N-1; i>=0; i--) cout<<res[i]<<" ";
    else cout<<"IMPOSSIBLE"<<endl;
}
