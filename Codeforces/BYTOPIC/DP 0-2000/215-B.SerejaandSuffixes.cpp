#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,M; cin>>N>>M;
    int A[N]; for(int&x:A) cin>>x;

    set<int> seen;
    int pref[N+1]; pref[N]=0;
    for(int i=N-1; i>=0; i--) {
        pref[i]=pref[i+1];
        if(seen.find(A[i])==seen.end()) {
            pref[i]++;
            seen.insert(A[i]);
        }
    }

    int l;
    while(M--) {
        cin>>l;
        cout<<pref[l-1]<<endl;
    }
}