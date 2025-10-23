#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("jkld.txt","r",stdin);

    int N,M; cin>>N>>M;
    int A[N],B[M];
    for(int&x:A) cin>>x;
    for(int&x:B) cin>>x;

    int i=0,j=0;
    while((i<N)&&(j<M)) {
        if(A[i]==B[j]) i++;
        j++;
    }

    if(i==N) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}