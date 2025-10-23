#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=1001;

int nxt[maxN];
bool vis[maxN];

int dfs(int i) {
    if(vis[i]) return i;
    vis[i]=1;
    return dfs(nxt[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;

    for(int i=1; i<=N; i++) cin>>nxt[i];

    for(int i=1; i<=N; i++) {
        fill(vis,vis+N+1,0);
        cout<<dfs(i)<<" ";
    }
}