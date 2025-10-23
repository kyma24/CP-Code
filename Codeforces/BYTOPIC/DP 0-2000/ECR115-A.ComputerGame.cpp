#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=100;

char grid[2][maxN];
bool vis[2][maxN];
void dfs(int i, int j, int&N) {
    if((i<0)||(j<0)||(i>=N)||(j>=N)||vis[i][j]||(grid[i][j]=='1')) return;
    vis[i][j]=1;
    for(int x=-1; x<=1; x++) for(int y=-1; y<=1; y++) dfs(i+x,j+y,N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        for(int i=0; i<2; i++) {
            for(int j=0; j<N; j++) cin>>grid[i][j];
            memset(vis[i],0,sizeof(vis[i]));
        }

        dfs(0,0,N);
        if(vis[1][N-1]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}