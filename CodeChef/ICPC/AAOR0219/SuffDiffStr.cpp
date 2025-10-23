#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ccin.txt","r",stdin);

    int T; cin>>T;
    while(T--) {
        string S; int K; cin>>S>>K;
        int N=S.length();
        
        bool chars[26];
        for(int i=0; i<26; i++) chars[i]=0;
        for(char c:S) chars[(c-'a')]=1;

        string res="";
        for(int i=0; i<26; i++) {
            if(res.length()==N) break;
            if(chars[i]) {
                if(K>0) {
                    res+=(char)('a'+i);
                    K--;
                }
            } else res+=(char)('a'+i);
        }

        if(res.length()<N) cout<<"NOPE"<<endl;
        else cout<<res<<endl;
    }
}