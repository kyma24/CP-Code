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
        string S; cin>>S; S+='B';
        int j; bool fl;
        for(int i=0; i<=N; i++) {
            if(S[i]!='?') {
                j=i-1, fl=(S[i]=='R');
                while(S[j]=='?') {
                    S[j]=((fl)?'B':'R');
                    fl=!fl; j--;
                }
                j=i+1, fl=(S[i]=='R');
                while(S[j]=='?') {
                    S[j]=((fl)?'B':'R');
                    fl=!fl; j++;
                }
            }
        }
        for(int i=0; i<N; i++) cout<<S[i];
        cout<<endl;
    }
}