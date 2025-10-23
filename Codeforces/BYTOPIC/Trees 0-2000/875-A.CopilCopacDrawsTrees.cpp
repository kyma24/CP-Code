#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;
const int maxN=2e5+1;

int ew[maxN], val[maxN]; // time of edge i->par[i], value
vector<pair<int,int>> adj[maxN];

void dfs(int i, int p) {
    int j,w;
    for(auto e:adj[i]) {
        tie(j,w)=e;
        if(j==p) continue;
        val[j]=val[i]+(w<ew[i]);
        ew[j]=w; dfs(j,i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        for(int i=1; i<=N; i++) adj[i].clear();

        int u,v;
        // input edges and update data
        for(int i=0; i<N-1; i++) {
            cin>>u>>v;
            adj[u].push_back({v,i+1});
            adj[v].push_back({u,i+1});
        }

        // construct tree & solve
        ew[1]=1; val[1]=1;
        dfs(1,0);
        
        int res=0;
        for(int i=1; i<=N; i++) res=max(res,val[i]);
        cout<<res<<endl;
    }
}