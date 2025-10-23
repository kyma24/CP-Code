#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("jkld.txt","r",stdin);

    int N,M; cin>>N>>M;

    map<ll,ll> A;
    for(int _=0; _<N; _++) {
        ll x,c; cin>>x>>c;
        A[x]+=c;
    }

    ll i=0,pos[A.size()],val[A.size()];
    memset(val,0,sizeof(val));
    for(auto p:A) {
        pos[i]=p.first;
        if(i>0) val[i]=val[i-1];
        val[i]+=p.second;
        i++;
    }

    while(M--) {
        ll l,r; cin>>l>>r;
        int indL=lower_bound(pos,pos+A.size(),l)-pos-1;
        int indR=upper_bound(pos,pos+A.size(),r)-pos-1;

        cout<<((indR>=0)?val[indR]:0)-((indL>=0)?val[indL]:0)<<endl;
    }
}