#include <bits/stdc++.h>
using namespace std;

int main() {
    string str="codeforces";
    int N; cin>>N;
    for(int i=0; i<N; i++) {
        char c; cin>>c;
        if(str.find(c)!=string::npos) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}