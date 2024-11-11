#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN=100000;

/*
algo: get topo ordering, then consider edges based on that
starting with most outgoing edges: you cannot get to only outgoing
from 1 if it isn't 1. 
*/

vector<int> adj[maxN+1];

vector<int> order; bool vis[maxN+1];
void topo(int i) {
    if(vis[i]) return;
    vis[i]=true;
    for(int j:adj[i]) topo(j);
    order.push_back(i);
}

int main() {
    //ifstream in("susinput.txt");
    int N,M; cin>>N>>M;
    for(int a,b,i=0; i<M; i++) {
        cin>>a>>b;
        adj[a].push_back(b);
    }

    bool flag=false;
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        topo(i);
    }

    reverse(order.begin(),order.end());
    int dist[maxN+1],par[maxN+1];
    fill(dist,dist+maxN+1,-1e9); dist[1]=0;
    for(int i:order) {
        for(int j:adj[i]) {
            if(dist[i]+1>dist[j]) {
                dist[j]=dist[i]+1;
                par[j]=i;
            }
        }
    }

    if(dist[N]<0) cout<<"IMPOSSIBLE"<<endl;
    else {
        vector<int> res; int cur=N;
        while(cur!=1) {
            res.push_back(cur);
            cur=par[cur];
        }
        
        cout<<1+res.size()<<endl<<1<<" ";
        for(int i=res.size()-1; i>=0; i--) cout<<res[i]<<" ";
    }
}