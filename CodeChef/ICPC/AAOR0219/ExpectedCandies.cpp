#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

double dp[1000][1000][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("ccin.txt","r",stdin);

    cout<<fixed<<setprecision(12);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        double A[N]; for(auto&x:A) cin>>x;
        
        // reset
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                dp[i][j][0]=0;
                dp[i][j][1]=0;
            }
        }

        // base case
        for(int i=0; i<N; i++) {
            dp[i][i][0]=A[i];
            dp[i][i][1]=0;
        }

        // counting
        for(int x=1; x<N; x++) {
            for(int i=0; i+x<N; i++) {
                dp[i][i+x][0]=((A[i]+dp[i+1][i+x][1])/2)+((A[i+x]+dp[i][i+x-1][1])/2);
                dp[i][i+x][1]=(dp[i+1][i+x][0]/2)+(dp[i][i+x-1][0]/2);
            }
        }

        double res=dp[0][N-1][0];
        cout<<res<<endl;
    }
}