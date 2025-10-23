#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,Q; cin>>N>>Q;
    string S; cin>>S;

    ll pref[N+1]; pref[0]=0;
    for(int i=0; i<N; i++) pref[i+1]=pref[i]+((int)S[i])-96;

    while(Q--) {
        int l,r; cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<endl;
    }
}