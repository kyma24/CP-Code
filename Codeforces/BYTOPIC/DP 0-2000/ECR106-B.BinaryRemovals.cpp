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

        int flag=0; char prev;
        for(char c:S) {
            if(flag==2) {
                if((c==prev)&&(c=='0')) {
                    flag=3; break;
                }
                prev=c;
                continue;
            }
            if(c=='1') flag++;
            else flag=0;
            prev=c;
        }

        if(flag==3) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}