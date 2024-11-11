#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //ifstream in("susinput.txt");
    int N,M; cin>>N>>M;
    vector<vector<ll>> edges;
    for(ll a,b,c,i=0; i<M; i++) {
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    vector<ll> dist(N+1,1e13),par(N+1); dist[1]=0;
    int pt=0;
    // bellman-ford
    for(ll a,b,c,i=1; i<=N; i++) {
        for(auto e:edges) {
            a=e[0]; b=e[1]; c=e[2];
            if(dist[a]+c<dist[b]) {
                dist[b]=dist[a]+c;
                par[b]=a;
                if(i==N) {
                    // child connected to negative cycle
                    pt=b;
                    break;
                }
            }
        }
    }

    if(pt) {
        cout<<"YES"<<endl;
        vector<bool> vis(N+1); vector<int> cyc;
        // trace from pt along parent array
        cyc.push_back(pt);
        while(!vis[pt]) {
            vis[pt]=true;
            pt=par[pt];
            cyc.push_back(pt);
        }
        // output cycle
        cout<<pt<<" ";
        for(int i=cyc.size()-2; i>=0; i--) {
            cout<<cyc[i]<<" ";
            if(cyc[i]==pt) break;
        }
    } else cout<<"NO"<<endl;
}