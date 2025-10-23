#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=1e5+1;

// combining the edges of the two graphs doesn't work.

set<int> adj[maxN];
vector<vector<int>> cc;
int vis[maxN];
// establishes connected components
void init(int i, int p) {
    if(vis[i]) return;
    vis[i]=1;
    cc.back().push_back(i);
    for(int j:adj[i]) if(j!=p) init(j,i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("jkld.txt","r",stdin);
    
    int N,M,tmp; cin>>N>>M>>tmp;
    M+=tmp;
    int u,v;
    while(M--) {
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        cc.push_back({});
        init(i,0);
    }

    auto lmb=[](vector<int> a, vector<int> b) {return (a.size()<b.size());};
    sort(cc.begin(),cc.end(),lmb);

    vector<pair<int,int>> res;
    pair<int,int> cur;
    for(int i=1; i<cc.size(); i++) {
        cur={-1,-1};
        for(int j:cc[i-1]) {
            if(vis[j]==2) continue;
            vis[j]=2;
            cur.first=j;
        }
        for(int k:cc[i]) {
            if(vis[k]==2) continue;
            vis[k]=2;
            cur.second=k;
        }
        if((cur.first>0)&&(cur.second>0)) res.push_back(cur);
    }

    for(auto x:cc) {
        for(int i:x) cout<<i<<" ";
        cout<<endl;
    }
    cout<<endl;

    cout<<res.size()<<endl;
    for(auto p:res) cout<<p.first<<" "<<p.second<<endl;
}