#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        // last non-1 before the end of A
        int last=-1,A[N];
        for(int i=0; i<N; i++) {
            cin>>A[i];
            if(A[i]!=1) last=i;
        }
        if(last==-1) {
            cout<<((N%2)?"First":"Second")<<endl;
            continue;
        }

        int i=0,num=0;
        while(A[i++]==1) num++;

        if(num%2) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
}