#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,D; cin>>N>>D;
    string S; cin>>S;

    int i=0, nw, res=0;
    while(i!=N-1) {
        nw=-1;
        for(int j=min(D,N-1-i); j>0; j--) {
            if(S[i+j]=='1') {
                nw=i+j;
                break;
            }
        }

        if(nw<0) break;
        i=nw; res++;
    }

    if(i==N-1) cout<<res<<endl;
    else cout<<-1<<endl;
}