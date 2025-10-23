#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    vector<bool>prime(1e6+1,1);
    for(int p=2; p*p<=1e6+1; p++) {
        if(!prime[p]) continue;
        for(int i=p*p; i<=1e6+1; i+=p) prime[i]=0;
    }

    int N; cin>>N;
    
    int M=1;
    while(M<=1e3) {
        if(!prime[(N*M)+1]) break;
        M++;
    }

    cout<<M<<endl;
}