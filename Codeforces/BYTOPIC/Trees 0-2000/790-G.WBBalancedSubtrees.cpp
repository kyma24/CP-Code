#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pa;

int solve(int i, vector<vi>&adj, vector<bool>&col, vector<pa>&dp) {
    int res=0;
    for(int j:adj[i]) {
        res+=solve(j,adj,col,dp);
        dp[i].first+=dp[j].first;
        dp[i].second+=dp[j].second;
    }
    return res+(dp[i].first==dp[i].second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifstream in("jkld.txt");

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        vector<vi> adj(N+1);
        for(int i=2; i<=N; i++) {
            int p; cin>>p;
            adj[p].push_back(i);
        }
        vector<bool> col(N+1);
        vector<pa> dp(N+1);
        for(int i=1; i<=N; i++) {
            char c; cin>>c;
            col[i]=(c=='B');
            dp[i]={(c=='W'),(c=='B')};
        }
        cout<<solve(1,adj,col,dp)<<endl;
    }
}