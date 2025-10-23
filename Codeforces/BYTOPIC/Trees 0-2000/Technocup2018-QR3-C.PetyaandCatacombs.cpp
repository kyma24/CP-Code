#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=2e5+1;

vector<int> adj[maxN];
bool vis[maxN];
void fill(int t) {
    vis[t]=1;
    for(int j:adj[t]) fill(j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;
    fill(vis,vis+N+1,0);
    for(int i=1; i<=N; i++) {
        int t; cin>>t;
        // only earliest child: the rest should be connected to it.
        if(!vis[t]) {
            adj[t].push_back(i);
            vis[t]=1;
        }
    }

    fill(vis,vis+N+1,0);
    int res=0;
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        fill(i);
        res++;
    }

    cout<<res<<endl;
}