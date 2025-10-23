#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int N; cin>>N;

    int F[N],vis[N]; memset(vis,0,sizeof(vis));
    for(int&x:F) {
        cin>>x;
        x--;
    }

    bool flag=0;
    for(int i=0; i<N; i++) {
        if(vis[i]) continue;
        int cnt=0, en=i;
        while(cnt<3) {
            en=F[en];
            cnt++;
        }
        if(i==en) {
            flag=1;
            break;
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}