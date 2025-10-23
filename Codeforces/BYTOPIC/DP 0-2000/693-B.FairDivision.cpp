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

        int x,one=0,two=0;
        for(int i=0; i<N; i++) {
            cin>>x;
            if(x==1) one++;
            else two++;
        }

        if(((one+2*two)%2==0)&&((N%2==0)||(one>0))) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}