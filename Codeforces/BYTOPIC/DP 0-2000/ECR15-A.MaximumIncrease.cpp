#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;

    int cur, prev=1e9, len=1, res=0;
    for(int i=0; i<N; i++) {
        cin>>cur;
        if(cur>prev) len++;
        else {
            res=max(res,len);
            len=1;
        }
        prev=cur;
    }

    cout<<max(res,len)<<endl;
}