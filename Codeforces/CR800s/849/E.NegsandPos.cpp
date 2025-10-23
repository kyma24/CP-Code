#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        int mm=1e9,negct=0,arr[N];
        long long res=0;
        for(int i=0; i<N; i++) {
            cin>>arr[i];
            mm=min(mm,abs(arr[i]));
            if(arr[i]<0) negct++;
            res+=abs(arr[i]);
        }

        if(negct%2) cout<<res-(2*mm)<<endl;
        else cout<<res<<endl;
    }
}