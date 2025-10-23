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
        int A[N]; for(int&x:A) cin>>x;

        int pref=0,suff=N-1;
        while((pref<N)&&(A[pref]==A[N-1])) pref++;
        while((suff>0)&&(A[suff-1]==A[N-1])) suff--;
        
        if(pref==N) {
            cout<<0<<endl;
            continue;
        }

        int i=suff-1,jump=N-suff,res=0;
        while(i>=pref) {
            if(A[i]==A[N-1]) {
                i--; jump++; continue;
            }
            i-=jump; jump*=2;
            res++;
        }

        cout<<res<<endl;
    }
}