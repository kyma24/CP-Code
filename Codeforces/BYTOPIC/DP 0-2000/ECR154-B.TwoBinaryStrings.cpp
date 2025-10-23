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
        string A,B; cin>>A>>B;
        int N=A.length();
        
        if(A==B) {
            cout<<"YES"<<endl;
            continue;
        }

        int flag=0;
        for(int i=0; i<N; i++) {
            if(A[i]!=B[i]) {
                flag=0; continue;
            }
            if(A[i]=='0') flag=1;
            else {
                if(++flag==2) break;
                else flag=0;
            }
        }

        if(flag==2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}