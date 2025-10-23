#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("jkld.txt","r",stdin);

    int N; cin>>N;
    for(int i=0; i<N; i++) {
        int a,cnt=0; cin>>a;
        for(int k=0; k<30; k++) {
            if(a&(1<<k)) cnt++;
        }
        cout<<cnt<<" ";
    }
}