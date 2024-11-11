#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007;
const int maxN=100001;

/*
NUMBER OF PATHS FROM 1->N
paths[i] and f(i): number of paths from 1->i
DP: reverse edges and start from N.
*/

vector<int> par[maxN];
int paths[maxN];

int f(int i) {
    if(paths[i]) return paths[i]%mod;
    for(int j:par[i]) paths[i]=(paths[i]+f(j))%mod;
    return paths[i]%mod;
}

int main() {
    //ifstream in("susinput.txt");
    int N,M; cin>>N>>M;
    for(int a,b,i=0; i<M; i++) {
        cin>>a>>b;
        // parent array
        par[b].push_back(a);
    }
    paths[1]=1;
    cout<<f(N)<<endl;
}