#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pvr {
    int i;
    int p;
};

// lesson: instead of passing a path every turn of bfs,
// keep track of parents and reconstruct path outside of loop

int main() {
    int N,M; cin>>N>>M;
    vector<vector<int>> adj(N+1);
    vector<int> vis(N+1),par(N+1),res;
    while(M--) {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool flag=true;
    pvr cur,nxt;
    cur.i=1; cur.p=0;
    queue<pvr> q; q.push(cur);
    while(!q.empty()) {
        cur=q.front(); q.pop();
        if(vis[cur.i]) continue;

        vis[cur.i]=vis[cur.p]+1;
        par[cur.i]=cur.p;
        
        if(cur.i==N) {
            flag=false;
            break;
        }

        nxt.p=cur.i;
        for(int j:adj[cur.i]) {
            nxt.i=j;
            q.push(nxt);
        }
    }

    if(flag) cout<<"IMPOSSIBLE"<<endl;
    else {
        cout<<vis[cur.i]<<endl;
        int np=N;
        for(int i=vis[cur.i]; i>=0; i--) {
            res.push_back(np);
            np=par[np];
        }
        for(int i=vis[cur.i]-1; i>=0; i--) cout<<res[i]<<" ";
    }
}