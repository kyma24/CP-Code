#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int maxdist(int i, int j, int N, int M) {
    int h=abs(M-1-j),v=abs(N-1-i);
    return max(i,v)+max(j,h);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int T; cin>>T;
    while(T--) {
        int N,M; cin>>N>>M;
        vector<int> dists;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                dists.push_back(maxdist(i,j,N,M));
            }
        }
        sort(dists.begin(),dists.end());
        for(int x:dists) cout<<x<<" ";
        cout<<endl;
    }
}