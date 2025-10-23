#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("","r",stdin);

    int T; cin>>T;
    while(T--) {
        double dtF,dtB,tA,bS; cin>>dtF>>dtB>>tA>>bS;

        double boltT=dtF/bS;
        if((tA*boltT*boltT/2)>=(dtB+dtF)) cout<<"Tiger"<<endl;
        else cout<<"Bolt"<<endl;
    }
}