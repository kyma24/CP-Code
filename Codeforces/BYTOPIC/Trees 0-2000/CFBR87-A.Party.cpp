#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN=2000;

vector<int> adj[maxN+1];

int dfs(int i, int d) {
    int curDep=d;
    for(int j:adj[i]) curDep=max(curDep,dfs(j,d+1));
    return curDep;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin>>N;

    vector<int> roots;
    for(int i=1; i<=N; i++) {
        int par; cin>>par;
        if(par<0) roots.push_back(i);
        else adj[par].push_back(i);
    }

    int maxDep=0;
    for(int x:roots) maxDep=max(maxDep,dfs(x,1));

    cout<<maxDep<<endl;
}