#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int grid[1000][1000],add[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("jkld.txt","r",stdin);

    int N,M,Q; cin>>N>>M>>Q;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>grid[i][j];
        }
    }

    int x1,y1,x2,y2,c;
    while(Q--) {
        cin>>x1>>y1>>x2>>y2>>c;
        x1--, y1--, x2--, y2--;
        add[x1][y1]+=c;
        if(x2+1<N) add[x2+1][y1]-=c;
        if(y2+1<M) add[x1][y2+1]-=c;
        if((x2+1<N)&&(y2+1<M)) add[x2+1][y2+1]+=c;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(i-1>=0) add[i][j]+=add[i-1][j];
            if(j-1>=0) add[i][j]+=add[i][j-1];
            if((i-1>=0)&&(j-1>=0)) add[i][j]-=add[i-1][j-1];
            grid[i][j]+=add[i][j];
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}