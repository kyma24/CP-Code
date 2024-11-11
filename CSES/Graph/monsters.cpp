#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N=1000,M=1000;
vector<vector<char>> grid(N,vector<char>(M));
vector<vector<int>> dist(N,vector<int>(M,1e6+1)),mdist(N,vector<int>(M,1e6+1));
vector<vector<bool>> vis(N,vector<bool>(M));

vector<pair<int,int>> add={pair<int,int>(-1,0),pair<int,int>(0,-1),pair<int,int>(1,0),pair<int,int>(0,1)};
char dir(int x, int y) {
    if(x==-1) return 'U';
    else if(x==0) {
        if(y==-1) return 'L';
        else return 'R';
    } else return 'D';
}

struct pic {
    int i;
    int j;
    int c;
};

struct piv {
    int i;
    int j;
    int v;
};

queue<piv> q;
piv coord; int i,j,v;
void bfs(bool&m) {
    while(!q.empty()) {
        coord=q.front(); q.pop();
        i=coord.i; j=coord.j; v=coord.v;
        if(m) mdist[i][j]=v;
        else dist[i][j]=v;
            
        for(auto p:add) {
            if((i+p.first<0)||(i+p.first>=N)||(j+p.second<0)||(j+p.second>=M)
            ||(grid[i+p.first][j+p.second]=='#')||vis[i+p.first][j+p.second]) continue;

            vis[i+p.first][j+p.second]=true;
            coord.i=i+p.first; coord.j=j+p.second; coord.v=v+1;
            q.push(coord);
        }
    }
}

vector<vector<pair<int,int>>> par(N,vector<pair<int,int>>(M));
queue<pic> qp;
pic val; char c; pair<int,int> en;
bool bfsolve(int s, int e) {
    val.i=s; val.j=e; val.c=0;
    qp.push(val);
    vis[s][e]=true;
    while(!qp.empty()) {
        val=qp.front(); qp.pop();
        i=val.i; j=val.j; c=val.c;
        
        if((i==0)||(i==N-1)||(j==0)||(j==M-1)) {
            en=pair<int,int>(i,j);
            return true;
        }

        for(auto p:add) {
            val.i=i+p.first; val.j=j+p.second; val.c=dir(p.first,p.second);
            if((val.i<0)||(val.i>=N)||(val.j<0)||(val.j>=M)||(grid[val.i][val.j]=='#')
            ||vis[val.i][val.j]||mdist[val.i][val.j]<=dist[val.i][val.j]) continue;

            vis[i+p.first][j+p.second]=true;
            par[i+p.first][j+p.second]=pair<int,int>(i,j);
            qp.push(val);
        }
    }
    return false;
}

int main() {
    //ifstream in("test_input.txt");
    cin>>N>>M;
    vector<pair<int,int>> mons;
    pair<int,int> start;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='A') start=pair<int,int>(i,j);
            if(grid[i][j]=='M') mons.push_back(pair<int,int>(i,j));
        }
    }
    bool tmp=true;
    // construct monster min dist array
    for(pair<int,int> pii:mons) {
        coord.i=pii.first; coord.j=pii.second; coord.v=0;
        q.push(coord);
        vis[coord.i][coord.j]=true;
    }
    bfs(tmp);
    for(auto&x:vis) fill(x.begin(),x.end(),false);

    
    tmp=false;
    coord.i=start.first; coord.j=start.second; coord.v=0;
    q.push(coord);
    vis[start.first][start.second]=true;
    // construct A dist array
    bfs(tmp);
    for(auto&x:vis) fill(x.begin(),x.end(),false);

    // bfs result
    if(bfsolve(start.first,start.second)) {
        cout<<"YES"<<endl;
        vector<char> res;
        int curi=en.first,curj=en.second;
        // backtrack based on parent array
        while((curi!=start.first)||(curj!=start.second)) {
            en=par[curi][curj];
            res.push_back(dir(curi-en.first,curj-en.second));
            curi=en.first; curj=en.second;
        }
        cout<<res.size()<<endl;
        for(int i=res.size()-1; i>=0; i--) cout<<res[i];
    } else cout<<"NO"<<endl;

    /*
    // flood fill result
    if(ffsolve(start.first,start.second,0)) {
        cout<<"YES"<<endl<<res.size()-1<<endl;
        for(int i=1; i<res.size(); i++) cout<<res[i];
    } else {
        cout<<"NO";
    }
    */
}