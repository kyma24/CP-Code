#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxN=2e5;

int N,A[maxN],score[maxN];

int solve(int i) {
    if(i>=N) return 0;
    if(score[i]>=0) return score[i];
    return score[i]=A[i]+solve(i+A[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int T; cin>>T;
    while(T--) {
        cin>>N;
        for(int i=0; i<N; i++) {
            cin>>A[i];
            score[i]=-1;
        }

        int res=0;
        for(int i=0; i<N; i++) if(score[i]<0) res=max(res,solve(i));
        
        cout<<res<<endl;
    }
}