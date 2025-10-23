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

        int res=0; char cur, prev='0';
        for(int i=0; i<N; i++) {
            cin>>cur;
            if((res%2==0)&&(cur<prev)) res++;
            if((res%2==1)&&(cur>prev)) res++;
            prev=cur;
        }

        cout<<res<<endl;
    }
}