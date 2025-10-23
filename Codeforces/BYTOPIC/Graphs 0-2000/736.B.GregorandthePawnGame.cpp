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
        string en,gr; cin>>en>>gr;

        int res=0;
        for(int i=0; i<N; i++) {
            if((gr[i]=='1')&&(en[i]=='0')) {
                res++;
                gr[i]='0';
            }
        }

        for(int i=0; i<N; i++) {
            if(gr[i]=='1') {
                if((i>0)&&(en[i-1]=='1')) {
                    res++; en[i-1]='0';
                    continue;
                }
                if((i<N-1)&&(en[i+1]=='1')) {
                    res++; en[i+1]='0';
                }
            }
        }

        cout<<res<<endl;
    }
}