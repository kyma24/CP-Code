#include <iostream>
#include <vector>
#include <string>
using namespace std;
// dfs is not updating the map, but i put a reference
// figure out why.
int n,m;
void dfs(int i, int j, vector<vector<char>> &mp) {
    if (!(i<0 || i>=n || j<0 || j>=m || mp[i][j]=='#')) {
        mp[i][j]='#';
        dfs(i-1,j,mp);
        dfs(i+1,j,mp);
        dfs(i,j-1,mp);
        dfs(i,j+1,mp);
    }
}

int main() {
    cin >> n >> m;
    vector<vector<char>> mp(n);
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        vector<char> temp(s.begin(),s.end());
        mp[i]=temp;
    }

    int count = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mp[i][j]=='.') {
                count ++;
                dfs(i,j,mp);
            }
        }
    }
    cout << count << endl;

}