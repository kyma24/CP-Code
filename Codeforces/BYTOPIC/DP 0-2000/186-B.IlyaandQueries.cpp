#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    string S; cin>>S;
    int N=S.length(),M; cin>>M;

    int pref[N+1]; pref[0]=0;
    for(int i=1; i<=N; i++) pref[i]=pref[i-1]+(S[i-1]==S[i]);

    int l,r;
    while(M--) {
        cin>>l>>r;
        cout<<pref[r-1]-pref[l-1]<<endl;
    }
}