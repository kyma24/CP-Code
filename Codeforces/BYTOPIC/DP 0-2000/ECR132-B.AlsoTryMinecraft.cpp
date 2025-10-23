#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,M; cin>>N>>M;
    ll A[N]; for(ll&x:A) cin>>x;

    ll pre[N], suf[N]; pre[0]=0, suf[N-1]=0;
    for(int i=1; i<N; i++) pre[i]=pre[i-1]+max(0ll,A[i-1]-A[i]);
    for(int i=N-2; i>=0; i--) suf[i]=suf[i+1]+max(0ll,A[i+1]-A[i]);

    while(M--) {
        int s,t; cin>>s>>t; s--, t--;
        if(s<=t) cout<<pre[t]-pre[s]<<endl;
        else cout<<suf[t]-suf[s]<<endl;
    }
}