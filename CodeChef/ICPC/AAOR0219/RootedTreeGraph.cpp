#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

vector<int> graph[100001];
vector<int> tree[100001];
int par[100001];
int subsize[100001];
bool seen[100001];

// fulfills defined conditions + all have a parent (but the root)
bool check(int i, int ancs) {
    seen[i]=1; 
    subsize[i]=0;
    for(int j:tree[i]) {
        if(seen[j]||(!check(j,ancs+1))) return 0;
        subsize[i]+=subsize[j]+1;
    }
    if((subsize[i]+ancs)!=graph[i].size()) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ccin.txt","r",stdin);

    int Q; cin>>Q;
    while(Q--) {
        int N,M; cin>>N>>M;

        for(int i=1; i<=N; i++) graph[i].clear();
        for(int i=1; i<=N; i++) tree[i].clear();
        fill(par,par+N+1,-1);
        fill(seen,seen+N+1,false);

        while(M--) {
            int u,v; cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ord[N]; iota(ord,ord+N,1);
        auto comp=[](int a, int b) {
            return graph[a].size()>graph[b].size();
        };
        sort(ord,ord+N,comp);
        int root=ord[0];

        par[root]=0; 
        for(int i=0; i<N; i++) {
            seen[ord[i]]=1;
            for(int x:graph[ord[i]]) {
                if(seen[x]) continue;
                par[x]=ord[i];
            }
        }

        bool flag=0;
        for(int i=1; i<=N; i++) {
            if(par[i]<0) {
                flag=1;
                break;
            }
        }
        if(flag) {
            cout<<"NO"<<endl;
            continue;
        }

        // set up tree
        for(int i=1; i<=N; i++) {
            if(par[i]>0) {
                tree[par[i]].push_back(i);
            }
        }
        fill(seen,seen+N+1,false);

        if(check(root,0)) {
            cout<<"YES"<<endl;
            for(int i=1; i<=N; i++) cout<<par[i]<<" ";
            cout<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}