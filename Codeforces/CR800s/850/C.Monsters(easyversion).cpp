#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        int a[N];
        for(int i=0; i<N; i++) cin>>a[i];
        sort(a,a+N);
        // binsearch for first non-one hp index(hi)
        int hi=N-1,lo=0,mid;
        while(lo<(hi-1)) {
            mid=(hi+lo)/2;
            if(a[mid]==1) lo=mid;
            else hi=mid;
        }
        if(a[lo]!=1) hi=lo;
        // init starting value
        long long res=0,cur;
        if(!hi) cur=0;
        else cur=1;
        for(int i=hi;i<N;i++) {
            if(a[i]>=(cur+1)) cur++;
            res+=a[i]-cur;
        }
        cout<<res<<endl;
    }
}