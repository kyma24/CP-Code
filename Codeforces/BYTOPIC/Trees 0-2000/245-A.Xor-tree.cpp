#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<vector<int>> vvi;

// op=-1: no operations are passed down at all
// op=0: operate on child
// op=1: operate on self
void solve(int i, int p, bool d, pair<int,int> flip, vvi&adj, vector<bool>&change, vector<int>&res) {
    int cur=(d?flip.first:flip.second);
    // wrong after current operation?
    // !((need change) xor (operate on self))
    if(change[i]^(cur==1)) {
        cur=(cur<1); // -1 or 0 -> 1, 1-> 0
        res.push_back(i);
    }
    for(int j:adj[i]) {
        if(j==p) continue;

        if(d) flip.first=cur;
        else flip.second=cur;
        solve(j,i,!d,flip,adj,change,res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("jkld.txt","r",stdin);

    int N; cin>>N;
    vvi adj(N+1);
    for(int i=1; i<N; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> change(N+1);
    for(int i=1; i<=N; i++) {
        int init; cin>>init;
        change[i]=init;
    }
    for(int i=1; i<=N; i++) {
        int goal; cin>>goal;
        change[i]=(change[i]!=goal);
    }

    vector<int> res;
    solve(1,0,0,{-1,-1},adj,change,res);

    cout<<res.size()<<endl;
    for(int x:res) cout<<x<<endl;
}