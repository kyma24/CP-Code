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

        map<int,int> rng;
        for(int i=0; i<N; i++) {
            int a; cin>>a;
            if(a>0) rng[max(0,i-a+1)]=i;
        }

        int res[N]={0}; int cur=0;
        for(auto p:rng) {
            int l,r; tie(l,r)=p;
            while(cur<l) res[cur++]=0;
            while(cur<=r) res[cur++]=1;
        }
        
        
        for(int x:res) cout<<x<<" ";
        cout<<endl;
    }
}