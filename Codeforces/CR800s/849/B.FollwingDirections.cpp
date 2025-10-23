#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    for(int i=0; i<T; i++) {
        int N; cin>>N;
        string dir; cin>>dir;
        int flag=0,coords[2];
        coords[0]=0; coords[1]=0;
        for(int j=0; j<N; j++) {
            if(dir[j]=='U') coords[1]++;
            if(dir[j]=='R') coords[0]++;
            if(dir[j]=='D') coords[1]--;
            if(dir[j]=='L') coords[0]--;
            if((coords[0]==1)&&(coords[1]==1)) {
                flag=1; break;
            }
        }
        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}