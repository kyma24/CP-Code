#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN=2e5;

// maximum depth, depths
ll depMax, dep[maxN+1];
// stores 2 deepest ancestors
pair<int,int> depCh[maxN+1];
vector<int> adj[maxN+1];

void setup(int i, int p) {
    depCh[i].first=i;
    for(int j:adj[i]) {
        if(j==p) continue;
        dep[j]=dep[i]+1;
        setup(j,i);
        if(dep[depCh[i].first]<dep[depCh[j].first]) {
            depCh[i].second=depCh[i].first;
            depCh[i].first=depCh[j].first;
        }
        else if(dep[depCh[i].second]<dep[depCh[j].first]) {
            depCh[i].second=depCh[j].first;
        }
    }
    depMax=max(depMax,dep[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int N; ll K,C; cin>>N>>K>>C;
        for(int i=0; i<=N; i++) {
            adj[i].clear();
            dep[i]=0;
            depCh[i]={0,0};
        }

        for(int i=1; i<N; i++) {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dep[1]=0;
        depMax=0;
        setup(1,0);

        // if no profit from 1 operation
        if(K<=C) {
            cout<<depMax*K<<endl;
            continue;
        }

        ll cur,loss,res=0;
        // find max profit of path going through i
        for(int i=1; i<=N; i++) {
            cur=dep[depCh[i].first]-dep[i]
               +dep[depCh[i].second]-dep[i];
            loss=min(dep[depCh[i].first],dep[depCh[i].second]);
            res=max(res,(cur*K)-(loss*C));
        }

        cout<<res<<endl;
    }
}