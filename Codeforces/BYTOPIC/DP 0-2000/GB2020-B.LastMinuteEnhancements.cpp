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
        map<int,int> X;
        for(int i=0; i<N; i++) {
            int x; cin>>x;
            X[x]++;
        }

        set<int> S;
        for(auto p:X) {
            if(S.count(p.first)) {
                S.insert(p.first+1);
            } else {
                if(p.second>1) S.insert(p.first+1);
                S.insert(p.first);
            }
        }

        cout<<S.size()<<endl;
    }
}