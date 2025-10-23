#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;

    bool flag=1;
    int root=0, adj[N+1];
    set<int> leaf;

    memset(adj,0,sizeof(adj));
    for(int i=1; i<N; i++) {
        int u,v; cin>>u>>v;
        adj[u]++; adj[v]++;
        if(adj[u]>2) {
            if((root>0)&&(root!=u)) {
                flag=0; break;
            }
            root=u;
        }
        if(adj[v]>2) {
            if((root>0)&&(root!=v)) {
                flag=0; break;
            }
            root=v;
        }
    }

    for(int i=1; i<=N; i++) if(adj[i]==1) leaf.insert(i);

    if(!flag) cout<<"No"<<endl;
    else {
        cout<<"Yes"<<endl;
        if(root==0) {
            root=*leaf.begin();
            cout<<leaf.size()-1<<endl;
        } else cout<<leaf.size()<<endl;
        for(int x:leaf) if(root!=x) cout<<root<<" "<<x<<endl;
    }
}