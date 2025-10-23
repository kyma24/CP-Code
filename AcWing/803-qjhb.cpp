#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("jkld.txt","r",stdin);

    int N; cin>>N;
    pair<int,int> inters[N];
    for(auto&p:inters) cin>>p.first>>p.second;
    sort(inters,inters+N);

    int cnt=0; pair<int,int> prev=inters[0],cur;
    for(int i=1; i<N; i++) {
        cur=inters[i];
        if(cur.first<=prev.second) prev={prev.first,max(cur.second,prev.second)};
        else {
            cnt++; prev=inters[i];
        }
    }

    cout<<cnt+1<<endl;
}