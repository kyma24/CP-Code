#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=1e5+1;

// if same cc, return false. else, union and return true.
void uni(int p, int q, vector<int>&id,vector<int>&sz) {
    int i,j;
    for(i=p; i!=id[i]; i=id[i]) id[i]=id[id[i]];
    for(j=q; j!=id[j]; j=id[j]) id[j]=id[id[j]];
    if(i==j) return;
    if(sz[i]<sz[j]) {
        id[i]=j;
        sz[j]+=sz[i];
    } else {
        id[j]=i;
        sz[i]+=sz[j];
    }
}

bool find(int p, int q, vector<int>&id) {
    int i,j;
    for(i=p; i!=id[i]; i=id[i]) id[i]=id[id[i]];
    for(j=q; j!=id[j]; j=id[j]) id[j]=id[id[j]];
    if(i==j) return 0;
    return 1;
}

void setup(int N,vector<int>&id,vector<int>&sz,vector<pair<int,int>>&edges) {
    for(int i=1; i<=N; i++) {
        id[i]=i;
        sz[i]=1;
    }
    int p,q;
    for(auto e:edges) {
        p=e.first; q=e.second;
        uni(p,q,id,sz);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,M1,M2; cin>>N>>M1>>M2;

    vector<int> idM(N+1),idD(N+1),szM(N+1),szD(N+1);
    vector<pair<int,int>> edgesM,edgesD;
    while(M1--) {
        int u,v; cin>>u>>v;
        edgesM.push_back({u,v});
    }
    setup(N,idM,szM,edgesM);
    while(M2--) {
        int u,v; cin>>u>>v;
        edgesD.push_back({u,v});
    }
    setup(N,idD,szD,edgesD);

    // union find(if not same cc, union)
    bool tmpM,tmpD;
    vector<pair<int,int>> res;
    for(int i=1; i<N; i++) {
        for(int j=i+1; j<=N; j++) {
            tmpM=find(i,j,idM), tmpD=find(i,j,idD);
            if(tmpM&&tmpD) {
                uni(i,j,idM,szM);
                uni(i,j,idD,szD);
                res.push_back({i,j});
            }
        }
    }

    cout<<res.size()<<endl;
    for(auto e:res) cout<<e.first<<" "<<e.second<<endl;
}