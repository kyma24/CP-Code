#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cur,tmp,N=1e5;
vector<vector<int>> adj(N+1);
vector<int> vis(N+1),path;
// dfs, keep track of path; if doesn't work, pop out.
int dfs(int i, int p) {
    if(vis[i]) return i;
    vis[i]=true;
    for(int j:adj[i]) {
        if(j==p) continue;
        path.push_back(j);
        cur=dfs(j,i);
        if(cur) return cur;
        path.pop_back();
    }
    return 0;
}

int main() {
    int M; cin>>N>>M;
    for(int a,b,i=0; i<M; i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool flag=true;
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        cur=i; path={i};
        cur=dfs(i,0);
        if(dfs(i,0)) {
            tmp=find(path.begin(),path.end(),cur)-path.begin();
            // this if statement is stupid;
            // paths < 4 are i->i or i->j->i, already accounted for
            // in data and dfs.
            if((path.size()-tmp)>=4) {
                flag=false;
                break;
            }
        }
    }

    if(flag) cout<<"IMPOSSIBLE";
    else {
        cout<<path.size()-tmp<<endl;
        flag=false;
        for(int i:path) {
            if(i==cur) flag=true;
            if(flag) cout<<i<<" ";
        }
    }
}