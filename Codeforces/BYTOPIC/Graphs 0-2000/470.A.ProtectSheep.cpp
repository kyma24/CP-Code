#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int R,C;
char grid[500][500];
bool vis[500][500],flag;

bool in(int i, int j) {
    return ((i>=0)&&(j>=0)&&(i<R)&&(j<C));
}

void f(int i, int j) {
    if((!flag)||vis[i][j]||(grid[i][j]!='S')) return;

    vis[i][j]=1;
    for(int a=-1; a<=1; a+=2) {
        if(in(i+a,j)) {
            if(grid[i+a][j]=='.') grid[i+a][j]='D';
            if(grid[i+a][j]=='W') {
                flag=0; return;
            }
            f(i+a,j);
        }
        if(in(i,j+a)) {
            if(grid[i][j+a]=='.') grid[i][j+a]='D';
            if(grid[i][j+a]=='W') {
                flag=0; return;
            }
            f(i,j+a);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    cin>>R>>C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin>>grid[i][j];
            vis[i][j]=0;
        }
    }

    flag=1;
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) f(i,j);
    if(!flag) cout<<"No"<<endl;
    else {
        cout<<"Yes"<<endl;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) cout<<grid[i][j];
            cout<<endl;
        }
    }
}