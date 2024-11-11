#include <bits/stdc++.h>
using namespace std;

int visited[100001];
vector<vector<int>> adj(100001),jda(100001);
void dfs(int i, vector<vector<int>>& v) {
    visited[i]=1;
    for(int j:v[i]) 
        if(!visited[j]) dfs(j,v);
}

int main() {
    int N,M; cin>>N>>M;
    while(M--) {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }
    
    int flag=1;
    dfs(1,adj);
    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            cout<<"NO"<<endl<<1<<" "<<i;
            flag=0;
            break;
        }
    }

    if(flag) {
        for(int i=1; i<=N; i++) visited[i]=0;
        dfs(1,jda);
        for(int i=1; i<=N; i++) {
            if(!visited[i]) {
                cout<<"NO"<<endl<<i<<" "<<1;
                flag=0;
                break;
            }
        }

        if(flag) cout<<"YES";
    }
}