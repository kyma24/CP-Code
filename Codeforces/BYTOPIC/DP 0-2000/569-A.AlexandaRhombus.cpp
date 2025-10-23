#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;

    ll res=1, cur=0;
    while(N--) {
        res+=cur;
        cur+=4;
    }

    cout<<res<<endl;
}