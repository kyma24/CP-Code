#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN=1e5;

vector<int> adj[maxN+1];
set<int> odd,even;
bool col[maxN+1];
void dfs(int i, int p, bool c) {
    col[i]=c;
    if(c) odd.insert(i);
    else even.insert(i);
    for(int j:adj[i]) {
        if(j==p) continue;
        dfs(j,i,!c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin>>N;
    for(int i=1; i<N; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,1);

    ll res=0;
    for(int i=1; i<=N; i++) {
        if(col[i]) res+=even.size()-adj[i].size();
        else res+=odd.size()-adj[i].size();
    }

    cout<<res/2<<endl;
}

/*
for(auto it=odd.begin(); it!=odd.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it=even.begin(); it!=even.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
*/