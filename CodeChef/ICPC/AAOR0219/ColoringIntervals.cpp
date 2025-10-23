#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

/*
logic?? greedy. focus on current range: everything overlapping it should be opposite color. (don't think abt previous ranges.)
current range changes when smth's only partially overlapping (hanging off the right edge). then, that becomes current range and process repeats.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ccin.txt","r",stdin);

    int T; cin>>T; 
    while(T--) {
        int N; cin>>N;

        tuple<int,int,int> cur, rngs[N];
        for(int i=0; i<N; i++) {
            cin>>get<0>(cur)>>get<1>(cur);
            get<2>(cur)=i;
            rngs[i]=cur;
        }
        sort(rngs,rngs+N);

        int res[N]; memset(res,-1,sizeof(res));

        int col=0;
        cur=rngs[0]; res[get<2>(cur)]=col;
        
        tuple<int,int,int> nxt;
        for(int i=1; i<N; i++) {
            nxt=rngs[i];
            res[get<2>(nxt)]=((get<0>(nxt)<=get<1>(cur))?(1-col):col);
            
            if(get<1>(nxt)>get<1>(cur)) {
                cur=nxt;
                col=res[get<2>(nxt)];
            }
        }

        for(int x:res) cout<<x;
        cout<<endl;
    }
}