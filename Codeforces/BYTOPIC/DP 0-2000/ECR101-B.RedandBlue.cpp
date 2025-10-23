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

        int R=0,B=0,cur,sum=0;
        for(int i=0; i<N; i++) {
            cin>>cur; sum+=cur;
            R=max(R,sum);
        }

        int M; cin>>M;
        sum=0;
        for(int i=0; i<M; i++) {
            cin>>cur; sum+=cur;
            B=max(B,sum);
        }

        cout<<max(0,R+B)<<endl;
    }
}