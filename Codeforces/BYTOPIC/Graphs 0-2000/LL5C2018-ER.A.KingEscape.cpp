#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int N,ax,ay,cx,cy,vis[1000][1000];

bool check(int x, int y) {
    // diagonals, vertical(same x), horizontal(same y)
    return ((abs(ax-x)==abs(ay-y))||(ax==x)||(ay==y));
}

bool solve(int x, int y) {
    if((x<0)||(x>=N)||(y<0)||(y>=N)||check(x,y)||vis[x][y]) return 0;
    vis[x][y]=1;
    if((x==cx)&&(y==cy)) return 1;

    for(int dx=-1; dx<=1; dx++) for(int dy=-1; dy<=1; dy++) if(solve(x+dx,y+dy)) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    cin>>N;

    int bx,by; cin>>ax>>ay>>bx>>by>>cx>>cy;
    ax--; ay--; bx--; by--; cx--; cy--;

    for(auto&x:vis) fill(x,x+N,0);

    if(solve(bx,by)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}