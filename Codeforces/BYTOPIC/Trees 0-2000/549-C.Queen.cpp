#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=1e5+1;

vector<int> adj[maxN];
bool resp[maxN];

void dfs(int i, set<int>&res) {
    bool del=resp[i];
    for(int j:adj[i]) {
        dfs(j,res);
        del=del&resp[j];
    }
    if(del) res.insert(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;
    int root=-1,p,c;
    for(int i=1; i<=N; i++) {
        cin>>p>>c;
        if(p<0) root=i;
        else {
            adj[p].push_back(i);
            resp[i]=c;
        }
    }

    set<int> res;
    dfs(root,res);
    if(res.size()>0) for(int x:res) cout<<x<<" ";
    else cout<<-1;
}