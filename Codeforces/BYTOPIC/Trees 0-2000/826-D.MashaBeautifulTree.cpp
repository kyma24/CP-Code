#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
recursion :3
binary search/merge sort -esque implementation,
preorder traversal as well, process validity of leaf nodes first.

also beware of edge cases like when M=1, the only wrong part about the code
*/

void swapRange(int l1, int l2, int r1, vector<int>&P) {
    for(int i=0; i<=r1-l1; i++) swap(P[l1+i],P[l2+i]);
}

int split(int l, int r, vector<int>&P) {
    if(r-l==0) return 0;
    if(r-l==1) {
        if(P[r]<P[l]) {
            swap(P[r],P[l]);
            return 1;
        }
        return 0;
    }
    int m=(l+r)/2;
    int lc=split(l,m,P), rc=split(m+1,r,P);
    if(P[l]>P[r]) {
        swapRange(l,m+1,m,P);
        return lc+rc+1;
    }
    return lc+rc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //ifstream in("jkld.txt");

    int T; cin>>T;
    while(T--) {
        int M; cin>>M;
        vector<int> P(M); for(int&x:P) cin>>x;

        int res=split(0,M-1,P);
        for(int i=1; i<M; i++) {
            if(P[i]<P[i-1]) {
                res=-1;
                break;
            }
        }
        cout<<res<<endl;
    }
}