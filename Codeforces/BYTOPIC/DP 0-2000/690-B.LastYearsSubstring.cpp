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
        string S; cin>>S;

        string tt="2020";
        int pos=0;
        while(pos<4) {
            if(tt[pos]!=S[pos]) break;
            pos++;
        }

        for(int i=N-4+pos; i<N; i++) {
            if(tt[pos]!=S[i]) break;
            pos++;
        }

        if(pos==4) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}