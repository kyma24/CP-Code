#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    ll N; cin>>N;
    if(N%2==0) cout<<(ll)powl(2,N/2)<<endl;
    else cout<<0<<endl;
}