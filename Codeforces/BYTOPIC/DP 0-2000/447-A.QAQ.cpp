#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    string str; cin>>str;
    int N=str.length();

    set<int> A;
    for(int i=0; i<N; i++) if(str[i]=='A') A.insert(i);
    
    int bef[N]; bef[0]=(str[0]=='Q');
    for(int i=1; i<N; i++) bef[i]=bef[i-1]+(str[i]=='Q');

    int aft[N]; aft[N-1]=(str[N-1]=='Q');
    for(int i=N-2; i>=0; i--) aft[i]=aft[i+1]+(str[i]=='Q');

    int res=0;
    for(int i:A) res+=bef[i]*aft[i];

    cout<<res<<endl;
}