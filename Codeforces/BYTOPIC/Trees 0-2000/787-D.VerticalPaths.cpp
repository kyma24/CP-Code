#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;

void solve(int i, int num, vvi&adj, vvi&res) {
    int cnt=num;
    for(int j:adj[i]) {
        res[cnt].push_back(j);
        solve(j,cnt,adj,res);
        cnt=res.size(); res.push_back({});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifstream in("jkld.txt");

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        int root;
        vvi adj(N+1);
        for(int i=1; i<=N; i++) {
            int p; cin>>p;
            if(i==p) root=i;
            else adj[p].push_back(i);
        }
        vvi res; res.push_back({root});
        solve(root,0,adj,res);

        int paths=0;
        for(int i=0; i<N; i++) {
            if(res[i].size()==0) continue;
            paths++;
        }
        cout<<paths<<endl;
        for(int i=0; i<N; i++) {
            if(res[i].size()==0) continue;
            cout<<res[i].size()<<endl;
            for(int j:res[i]) cout<<j<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
}