#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[401];
int dfs(int i,int d) {
    int maxdep=d;
    for(int j:adj[i]) maxdep=max(maxdep,dfs(j,d+1));
    return maxdep;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin>>N;
    vector<string> id; id.push_back("polycarp");
    for(int i=0; i<N; i++) {
        string str; cin>>str;
        transform(str.begin(),str.end(),str.begin(),::tolower);

        int to=find(id.begin(),id.end(),str)-id.begin();
        if(to==id.size()) id.push_back(str);

        cin>>str>>str;
        transform(str.begin(),str.end(),str.begin(),::tolower);

        int fr=find(id.begin(),id.end(),str)-id.begin();
        if(fr==id.size()) id.push_back(str);

        adj[fr].push_back(to);
    }

    cout<<dfs(0,1)<<endl;
}