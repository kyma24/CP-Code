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
        int A,B,C; cin>>A>>B>>C;
        cout<<(int)((B%2)==(C%2))<<" "<<(int)((A%2)==(C%2))<<" "<<(int)((A%2)==(B%2))<<endl;
    }
}