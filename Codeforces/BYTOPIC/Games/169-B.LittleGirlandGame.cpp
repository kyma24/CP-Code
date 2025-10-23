#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    string S; cin>>S;
    int N=S.length();

    map<char,int> num;
    for(int i=0; i<N; i++) num[S[i]]++;

    int cnt=0;
    for(auto p:num) cnt+=(p.second%2);

    if((cnt<2)||(N%2)) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}