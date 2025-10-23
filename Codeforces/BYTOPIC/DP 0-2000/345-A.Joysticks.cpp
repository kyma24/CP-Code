#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("jkld.txt","r",stdin);

    int A,B; cin>>A>>B;
    if(A>B) swap(A,B);

    // start: minutes to make A>=B
    int res=ceil((double)(B-A)/3); bool op=0;
    A+=res, B-=2*res;
    while((A>((op)?0:1))&&(B>((op)?1:0))) {
        if(op) A++, B-=2;
        else A-=2, B++;
        op=!op; res++;
    }

    cout<<res<<endl;
}