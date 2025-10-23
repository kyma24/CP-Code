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
        int N,M,X,Y; cin>>N>>M>>X>>Y;
        Y=min(Y,2*X);

        char A[N][M]; for(int i=0; i<N; i++) for(char&x:A[i]) cin>>x;

        int j,res=0;
        for(int i=0; i<N; i++) {
            j=0;
            while(j<M) {
                if(A[i][j]=='.') {
                    if(j<M-1) {
                        if(A[i][j+1]=='.') res+=Y;
                        else res+=X;
                        j++;
                    } else res+=X;
                }
                j++;
            }
        }

        cout<<res<<endl;
    }
}