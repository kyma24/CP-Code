#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<vector<pair<int,int>>> vvp;

// check if it is just one chain(each node has at most 1 child)
bool check(int i, int p, vvp&adj) {
    if(adj[i].size()>2) return false;
    for(auto pa:adj[i]) {
        int j=pa.first;
        if(j==p) continue;
        return check(j,i,adj);
    }
    return true;
}

void solve(int i, int p, bool alt, vvp&adj, vector<int>&edge) {
    for(auto pa:adj[i]) {
        int j=pa.first, v=pa.second;
        if(j==p) continue;
        edge[v]=(alt?2:3);
        solve(j,i,!alt,adj,edge);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        vvp adj(N+1);
        for(int i=1; i<N; i++) {
            int u,v; cin>>u>>v;
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }

        int root;
        for(int i=1; i<=N; i++) {
            if(adj[i].size()==1) {
                root=i;
                break;
            }
        }

        if(!check(root,0,adj)) {
            cout<<-1<<endl;
            continue;
        }

        vector<int> edge(N);
        solve(root,0,1,adj,edge);
        for(int i=1; i<N; i++) cout<<edge[i]<<" ";
        cout<<endl;
    }
}