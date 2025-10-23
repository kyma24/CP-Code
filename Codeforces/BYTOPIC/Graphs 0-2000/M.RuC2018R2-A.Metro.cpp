#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,S; cin>>N>>S;

    bool A[N], B[N];
    for(bool&x:A) cin>>x;
    for(bool&x:B) cin>>x;

    bool flag=0;
    for(int i=S; i<N; i++) {
        if(A[i]&&B[i]) {
            flag=1;
            break;
        }
    }

    if(!A[0]) cout<<((S==1)?"YES":"NO")<<endl;
    else cout<<((A[S-1]||(flag&&B[S-1]))?"YES":"NO")<<endl;
}