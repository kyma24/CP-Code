#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,n; cin>>N;
    n=floor((double)(sqrt(1+8*N)-1)/2);

    cout<<n--<<endl;
    int i=1;
    while(n--) cout<<i++<<" ";
    cout<<N-(i*(i-1)/2)<<endl;
}