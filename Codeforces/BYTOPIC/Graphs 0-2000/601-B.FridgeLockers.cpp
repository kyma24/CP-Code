#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int T; cin>>T;
    while(T--) {
        int N,M; cin>>N>>M;

        int res=0; pair<int,int> A[N];
        for(int i=0; i<N; i++) {
            cin>>A[i].first; A[i].second=i+1;
            res+=2*A[i].first;
        }

        if((N==2)||(M<N)) {
            cout<<-1<<endl;
            continue;
        }

        sort(A,A+N);
        int nm=M-N;
        while((M--)>N) res+=A[0].first+A[1].first;

        cout<<res<<endl;
        for(int i=1; i<=N; i++) cout<<i<<" "<<max(1,(i+1)%(N+1))<<endl;
        while(nm--) cout<<A[0].second<<" "<<A[1].second<<endl;
    }
}