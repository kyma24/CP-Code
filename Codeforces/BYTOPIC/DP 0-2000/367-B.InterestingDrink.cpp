#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;
    int X[N]; for(int&x:X) cin>>x;
    sort(X,X+N);

    int Q; cin>>Q;
    while(Q--) {
        int m; cin>>m;
        cout<<(upper_bound(X,X+N,m)-X)<<endl;
    }
}