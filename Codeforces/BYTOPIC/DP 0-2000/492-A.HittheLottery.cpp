#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("","r",stdin);

    int N; cin>>N;
    
    int res=0;
    for(int a:{100,20,10,5,1}) {
        res+=N/a;
        N%=a;
    }

    cout<<res<<endl;
}