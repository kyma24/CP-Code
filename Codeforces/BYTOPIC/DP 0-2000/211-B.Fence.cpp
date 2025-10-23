#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,K; cin>>N>>K;
    ll pref[N+1]; pref[0]=0;
    for(int i=1; i<=N; i++) {
        cin>>pref[i]; pref[i]+=pref[i-1];
    }

    int res; ll val=1e12;
    for(int i=1; i<=N-K+1; i++) {
        if(val>(pref[i+K-1]-pref[i-1])) {
            res=i; val=pref[i+K-1]-pref[i-1];
        }
    }

    cout<<res<<endl;
}