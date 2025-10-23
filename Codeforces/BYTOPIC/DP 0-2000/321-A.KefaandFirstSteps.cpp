#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;
    int A[N]; for(int&x:A) cin>>x;

    int cur=1, res=0;
    for(int r=1; r<N; r++) {
        if(A[r]<A[r-1]) {
            res=max(res,cur);
            cur=1;
        }
        else cur++;
    }

    cout<<max(res,cur)<<endl;
}