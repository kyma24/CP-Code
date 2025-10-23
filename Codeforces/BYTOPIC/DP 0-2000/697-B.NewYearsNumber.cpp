#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;

        int y=(N%2020);
        if(N-(2021*y)>=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}