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
        string S; cin>>S;
        int N=S.length(), res=0;

        // calculate max
        for(int i=0; i<N; i++) res+=(S[i]!='0');

        int unit=-1, ten=-1;
        // min to get to -(2/7)5, -(0/5)0
        vector<tuple<char,char,char>> P={{'5','2','7'},{'0','0','5'}};
        for(auto p:P) {
            unit=-1, ten=-1;
            for(int i=N-1; i>=0; i--) {
                if((unit>=0)&&((S[i]==get<1>(p))||(S[i]==get<2>(p)))) {
                    ten=i; break;
                }
                if((unit<0)&&(S[i]==get<0>(p))) unit=i;
            }
            if((unit>=0)&&(ten>=0)) res=min(res,(N-1-unit)+(unit-ten-1));
        }

        cout<<res<<endl;
    }
}