#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,V; cin>>N>>V; N--;

    int tmp=max(0,N-V), res=min(N,V)-1+((tmp+1)*(tmp+2)/2);

    cout<<res<<endl;
}