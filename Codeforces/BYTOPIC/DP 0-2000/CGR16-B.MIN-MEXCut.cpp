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
        string S; cin>>S;
        
        int res=0; bool flag=0;
        for(int i=0; i<S.length(); i++) {
            if(res==2) break;

            if(S[i]=='0') {
                if(!flag) res+=(flag=1);
            } else flag=0;
        }

        cout<<res<<endl;
    }
}