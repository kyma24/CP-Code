#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout<<fixed<<setprecision(6);
    freopen("jkld.txt","r",stdin);

    double N; cin>>N;
    double lo=-10000,hi=10000,mid=0;
    while(hi-lo>=1e-8) {
        mid=lo+((hi-lo)/2);
        if((mid*mid*mid)<N) lo=mid;
        else hi=mid;
    }

    cout<<mid<<endl;
}