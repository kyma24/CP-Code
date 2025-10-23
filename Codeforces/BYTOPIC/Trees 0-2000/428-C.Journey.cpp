#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=1e5+1;

vector<int> adj[maxN];
int dep[maxN]; double prob[maxN];

void dfs(int i, int p, double d) {
    for(int j:adj[i]) {
        if(j==p) continue;
        dep[j]=dep[i]+1;
        prob[j]=prob[i]/(adj[i].size()-1+(i==1));
        dfs(j,i,d+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout<<fixed<<setprecision(15);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;

    for(int i=1; i<N; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dep[1]=0, prob[1]=1;
    dfs(1,0,1);
    
    double res=0;
    for(int i=2; i<=N; i++) if(adj[i].size()==1) res+=dep[i]*prob[i];
    
    cout<<res<<endl;
}