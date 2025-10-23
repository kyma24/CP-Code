#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

// boring way
ll merge(vector<int>&A, int l1, int r1, int l2, int r2) {
    ll ret=0;
    vector<int> res;

    int p1=l1,p2=l2;
    while((p1<=r1)&&(p2<=r2)) {
        if(A[p1]>A[p2]) {
            ret+=r1-p1+1; 
            res.push_back(A[p2]);
            p2++;
        } else {
            res.push_back(A[p1]);
            p1++;
        }
    }

    for(int i=p1; i<=r1; i++) res.push_back(A[i]);
    for(int i=p2; i<=r2; i++) res.push_back(A[i]);

    for(int i=l1; i<=r2; i++) A[i]=res[i-l1];
    return ret;
}

ll solve(vector<int>&A, int lo, int hi) {
    if(lo==hi) return 0;
    int mid=lo+((hi-lo)/2);

    ll ret=solve(A,lo,mid)+solve(A,mid+1,hi)+merge(A,lo,mid,mid+1,hi);
}

// header for ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("jkld.txt","r",stdin);

    int N; cin>>N;
    vector<int> A(N); for(int&x:A) cin>>x;
    
    cout<<solve(A,0,N-1)<<endl;

    // cool way
    ordered_multiset<int> cur; cur.insert(A[0]);
    ll res=0;
    for(int i=1; i<N; i++) {
        if(cur.lower_bound(A[i])!=cur.end()) {
            res+=(ll)(cur.size()-cur.order_of_key(A[i]+1));
        }
        cur.insert(A[i]);
    }
    
    cout<<res<<endl;
}