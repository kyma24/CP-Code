#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int part(vector<int>&A, int lo, int hi) {
    int pivot=A[hi],l=lo;
    for(int r=lo; r<hi; r++) {
        if(A[r]<=pivot) {
            swap(A[l],A[r]);
            l++;
        }
    }
    swap(A[l],A[hi]);
    return l;
}

int solve(vector<int>&A, int lo, int hi, int K) {
    int ind=part(A,lo,hi);
    if((ind-lo)==K) return A[ind];
    if((ind-lo)<K) return solve(A,ind+1,hi,K-(ind+1-lo));
    return solve(A,lo,ind-1,K);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("jkld.txt","r",stdin);
    
    int N,K; cin>>N>>K;
    K--;
    vector<int> A(N); for(int&x:A) cin>>x;
    cout<<solve(A,0,N-1,K)<<endl;
}