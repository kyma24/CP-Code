#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,M; cin>>N>>M;

    if((N-M)>(M-1)) cout<<min(N,M+1)<<endl;
    else cout<<max(1,M-1)<<endl;
}