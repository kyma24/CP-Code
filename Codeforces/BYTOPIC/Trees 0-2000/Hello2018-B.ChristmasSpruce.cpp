#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[1001];
bool dfs(int i) {
    if(adj[i].size()==0) return true;
    int leaf=0;
    for(int j:adj[i]) {
        leaf+=(adj[j].size()==0);
        if(!dfs(j)) return false;
    }
    if(leaf<3) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin>>N;
    for(int i=2; i<=N; i++) {
        int pi; cin>>pi;
        adj[pi].push_back(i);
    }

    if(dfs(1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}