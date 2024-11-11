#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //ifstream in("susinput.txt");
    int N,M,Q; cin>>N>>M>>Q;
    vector<vector<ll>> dist(N+1,vector<ll>(N+1,1e12));
    for(ll a,b,c,i=0; i<M; i++) {
        cin>>a>>b>>c;
        dist[a][b]=dist[b][a]=min(dist[a][b],c);
    }
    for(int i=1; i<=N; i++) dist[i][i]=0;

    // floyd-warshall: chose pivot for every pair
    for(int piv=1; piv<=N; piv++) {
        for(int i=1; i<=N; i++) {
            for(int j=i; j<=N; j++) {
                dist[i][j]=min(dist[i][j],dist[i][piv]+dist[piv][j]);
                dist[j][i]=dist[i][j];
            }
        }
    }

    int a,b;
    while(Q--) {
        cin>>a>>b;
        cout<<((dist[a][b]==1e12)?-1:dist[a][b])<<endl;
    }
}