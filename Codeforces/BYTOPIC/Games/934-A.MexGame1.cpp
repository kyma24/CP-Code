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
        map<int,int> A;
        for(int i=0; i<=N; i++) A[i]=0;
        for(int i=0; i<N; i++) {
            int a; cin>>a;
            A[a]++;
        }

        bool flag=0;
        for(auto p:A) {
            int val,cnt; tie(val,cnt)=p;
            if(cnt==0) {
                cout<<val<<endl;
                break;
            }
            if(cnt==1) {
                if(flag) {
                    cout<<val<<endl;
                    break;
                }
                flag=1;
            }
        }
    }
}