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
        
        int a,lv=101,lp=-1,gv=0,gp=-1;
        for(int i=1; i<=N; i++) {
            cin>>a;
            if(a<lv) lv=a, lp=i;
            if(a>gv) gv=a, gp=i;
        }

        // > to the right of <
        if(gp<lp) swap(lp,gp);

        // remove from both ends, one end only
        cout<<min(lp+N-gp+1,min(N-lp+1,gp))<<endl; 
    }
}