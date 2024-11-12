#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// digraph version of I
// same, except 3 STATES OF VISITED:
// not visited, processing, completely visited.
// nodes will not visit nodes from other components and think that there is a cycle
// because by marking with processing, you can tell if the node is in your component.
// ones already fully traversed from before will not be processed by other CC's.

int tmp,N=1e5;
vector<vector<int>> adj(N+1);
// 0: unvisited, 1:processing, 2:visited
vector<int> path,vis(N+1,-1);
// constructs path + returns ending node
int dfs(int i) {
    if(vis[i]==1) return i;
    // currently processing
    vis[i]=1;
    for(int j:adj[i]) {
        if(vis[j]==2) continue;
        path.push_back(j);
        tmp=dfs(j);
        if(tmp) return tmp;
        // looked thru every connection
        vis[j]=2;
        path.pop_back();
    }
    return 0;
}

int main() {
    int M; cin>>N>>M;
    for(int a,b,i=0; i<M; i++) {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    int en; bool flag=true;
    // for every CC
    for(int i=1; i<=N; i++) {
        // visited CC already
        if(vis[i]!=-1) continue;
        // reset path, dfs, fully visited
        path={i}, en=dfs(i), vis[i]=2;
        // no cycle in cc
        if(!en) continue;
        // cycle in CC
        flag=false;
        break;
    }

    if(flag) cout<<"IMPOSSIBLE"<<endl;
    else {
        int len=0,st;
        // find start of cycle
        for(int i=0; i<path.size(); i++) {
            if(path[i]==en) {
                st=i;
                break;
            }
        }
        // output
        cout<<path.size()-st<<endl;
        for(int i=st; i<path.size(); i++) cout<<path[i]<<" ";
    }
}
