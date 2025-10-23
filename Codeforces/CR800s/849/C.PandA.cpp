#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    for(int i=0; i<T; i++) {
        int flag=1,N; cin>>N;
        string str; cin>>str;
        for(int j=0; j<(N/2); j++) {
            if(str[j]==str[N-1-j]) {
                cout<<N-(j*2)<<endl;
                flag=0;
                break;
            }
        }
        if(flag) {
            if(N%2==0) cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
}