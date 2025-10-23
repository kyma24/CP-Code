#include <bits/stdc++.h>
using namespace std;

int digsum(int x) {
    int res=0;
    while(x) {
        res+=x%10;
        x/=10;
    }
    return res;
}

int main() {
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int N,Q; cin>>N>>Q;
        set<int> D;
        int arr[N];

        for(int i=0; i<N; i++) {
            cin>>arr[i];
            if(arr[i]>9) D.insert(i);
        }

        int l,r,type,curr;
        while(Q--) {
            cin>>type;
            if(type==1) {
                cin>>l>>r;
                l--; r--;
                curr=l; // to keep track of which item in the range
                while(!D.empty()) {
                    // set lower bound only requires the key
                    auto it=D.lower_bound(curr);
                    // if out of bounds [l,r]
                    if((it==D.end())||(*it>r)) break;
                    // sum digits and assign
                    arr[*it]=digsum(arr[*it]);
                    // if no more summing needed(already only one digit)
                    int sus=*it; // after deletion, *it will be sus
                    if(arr[*it]<10) D.erase(it);
                    // continue to next value in range
                    curr=sus+1;
                }
            } else {
                int out; cin>>out;
                cout<<arr[out-1]<<endl;
            }
        }
    }
}