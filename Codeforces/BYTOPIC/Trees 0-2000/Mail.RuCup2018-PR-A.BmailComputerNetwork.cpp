#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin>>N;
    int router[N]; router[0]=1;
    for(int i=1; i<N; i++) cin>>router[i];

    vector<int> res={N};
    int cur=N-1;
    while(cur!=0) {
        cur=router[cur]-1;
        res.push_back(cur+1);
    }

    for(auto it=res.end()-1; it>=res.begin(); it--) cout<<*it<<" ";
}