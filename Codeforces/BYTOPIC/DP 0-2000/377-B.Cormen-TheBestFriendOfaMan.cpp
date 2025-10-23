#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N,K; cin>>N>>K;
    
    int res=0, A[N]; cin>>A[0];
    for(int i=1; i<N; i++) {
        cin>>A[i];
        res+=max(0,K-A[i-1]-A[i]);
        A[i]=max(A[i],K-A[i-1]);
    }

    cout<<res<<endl;
    for(int x:A) cout<<x<<" ";
}