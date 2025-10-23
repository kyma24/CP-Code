#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=1e5+1;

int M;
vector<int> adj[maxN];
bool cat[maxN];

int solve(int i, int p, int m) {
    m=((cat[i])?(m+1):0);
    if(m>M) return 0;
    if((adj[i].size()==1)&&(i!=1)) return 1;

    int ret=0;
    for(int j:adj[i]) if(j!=p) ret+=solve(j,i,m);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N>>M;
    for(int i=1; i<=N; i++) cin>>cat[i];

    for(int i=1; i<N; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<solve(1,0,0)<<endl;
}