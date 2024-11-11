#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007;
using pll = pair<ll,ll>;
const int maxN=100001;

/*
MODIFIED DIJKSTRA: BFS
keep track of the 4 values dist, num, minf, maxf
reset and update accordingly

WHY KEEP VISITED?
Because an edge will be processed before another if its distance from 1 is smaller than the other's.
Take adjacency 1 -a-> 3 -b-> 2 , 1 -c-> 2 where 2 has other children
Cases:
(a+b)>c : might process edge a, but won't process edge b before edge c as a+b is greater than c
(a+b)=c : processing edges a and b is the same as processing edge c, so either way works
(a+b)<c : edges a and b will always be processed earlier than c because they will always be smaller
*/

int main() {
    //ifstream in("susinput.txt");
    int N,M; cin>>N>>M;
    vector<pll> adj[N+1];
    while(M--) {
        ll a,b,c; cin>>a>>b>>c;
        adj[a].push_back({c,b});
    }
    
    ll i,j,d,w,l,dist[N+1],num[N+1],minf[N+1],maxf[N+1];
    fill(dist,dist+N+1,1e15);
    fill(num,num+N+1,0);
    fill(minf,minf+N+1,1e15);
    fill(maxf,maxf+N+1,0);
    dist[1]=0; num[1]=1; minf[1]=0; maxf[1]=0;

    // cur dist from 1, cur node, cur length of route
    priority_queue<vector<ll>> q; q.push({0,1,0});
    bool vis[N+1]; fill(vis,vis+N+1,0);
    vector<ll> cur; 
    while(!q.empty()) {
        cur=q.top(); q.pop();
        d=-cur[0]; i=cur[1]; l=cur[2];
        if(vis[i]) continue;
        vis[i]=true;
        for(pll ch:adj[i]) {
            w=ch.first; j=ch.second;
            if((d+w)==dist[j]) { // found equal to min price
                num[j]+=num[i]; num[j]%=mod;
                minf[j]=min(minf[j],minf[i]+1); maxf[j]=max(maxf[j],maxf[i]+1);
                q.push({-dist[j],j,l+1});
            }
            if((d+w)<dist[j]) { // found smaller price
                dist[j]=d+w; 
                num[j]=num[i]; num[j]%=mod;
                minf[j]=minf[i]+1; maxf[j]=maxf[i]+1;
                q.push({-dist[j],j,l+1});
            }
        }
    }

    cout<<dist[N]<<" "<<num[N]<<" "<<minf[N]<<" "<<maxf[N]<<endl;
}