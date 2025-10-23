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
        
        int res=0;
        for(int i=1; i<=N; i++) {
            int a; cin>>a;
            if(a%2==0) res=i;
        }

        if(res>0) cout<<1<<endl<<res<<endl;
        else {
            if(N==1) cout<<-1<<endl;
            else cout<<2<<endl<<1<<" "<<2<<endl;
        }
    }
}