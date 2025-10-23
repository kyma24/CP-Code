#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=3e4+1;

vector<int> adj[maxN];
bool vis[maxN];

void dfs(int i) {
    vis[i]=1;
    for(int j:adj[i]) {
        if(vis[j]) continue;
        dfs(j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,T; cin>>N>>T;
    for(int i=1; i<N; i++) {
        int a; cin>>a;
        adj[i].push_back(i+a);
    }

    fill(vis,vis+N+1,0);
    dfs(1);
    if(vis[T]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}