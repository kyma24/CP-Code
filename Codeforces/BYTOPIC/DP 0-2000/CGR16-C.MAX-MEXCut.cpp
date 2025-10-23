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
        string A,B; cin>>A>>B;

        int res=0,cur,prev=10;
        for(int i=0; i<N; i++) {
            cur=0;
            if(A[i]!=B[i]) cur=2;
            else if(A[i]=='0') cur=1+(prev==0);
            else if((i>0)&&(prev==1)) cur=3;
            res+=cur-((cur>2)*2); prev=cur;
        }

        cout<<res<<endl;
    }
}