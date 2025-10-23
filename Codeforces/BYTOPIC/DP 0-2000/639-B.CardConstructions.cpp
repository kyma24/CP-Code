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
        ll N,res=0; cin>>N;
        while(N>1) {
            ll lo=1,hi=1e9,mid,H,val;
            while(lo<=hi) {
                mid=lo+((hi-lo)/2);
                if(mid*(3*mid+1)<=2*N) {
                    H=mid, val=mid*(3*mid+1)/2;
                    lo=mid+1;
                } else hi=mid-1;
            }
            N-=val; res++;
        }
        cout<<res<<endl;
    }
}