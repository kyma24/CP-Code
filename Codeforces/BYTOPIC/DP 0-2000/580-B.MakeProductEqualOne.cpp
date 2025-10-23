#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;

    ll res=0, neg=0; bool z=0;
    for(int i=0; i<N; i++) {
        int a; cin>>a;
        neg+=(a<0); z+=(a==0);
        res+=abs(abs(a)-1);
    }

    if((neg%2)&&(!z)) res+=2;
    cout<<res<<endl;
}