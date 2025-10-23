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
        int N,Q; cin>>N>>Q;

        bool S[N]; int cnt[N+1]; cnt[0]=0;
        for(int i=0; i<N; i++) {
            char c; cin>>c;
            S[i]=(c=='1');
            cnt[i+1]=cnt[i]+S[i];
        }

        while(Q--) {
            int l,r; cin>>l>>r;
            if(((S[l-1])?0:(l-1))-cnt[l-1]) cout<<"YES"<<endl;
            else if(((S[r-1]?0:(N-r))-(cnt[N]-cnt[r]))) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}