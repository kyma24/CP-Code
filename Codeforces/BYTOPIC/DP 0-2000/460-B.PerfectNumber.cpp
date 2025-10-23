#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int digSum(int n) {
    int ret=0;
    while(n!=0) {
        ret+=(n%10);
        n/=10;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int K; cin>>K;

    ll cur=1;
    while(K>0) {
        cur+=9;
        K-=(digSum(cur)==10);
    }

    cout<<cur<<endl;
}