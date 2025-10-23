#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int N,W,H; cin>>N>>W>>H;
        int a[N],b[N];
        for(int i=0; i<N; i++) cin>>a[i];
        for(int i=0; i<N; i++) cin>>b[i];

        int temp=b[0]-a[0];
        for(int i=0; i<N; i++) a[i]+=temp;

        int flag=1,lshift=W-H,rshift=W-H,shifted=0;
        for(int i=1; i<N; i++) {
            a[i]+=shifted;
            // all in bounds
            if((b[i]-H)>=(a[i]-W)&&(b[i]+H)<=(a[i]+W)) {
                // update lshift & rshift
                lshift=min(lshift,(a[i]+W)-(b[i]+H));
                rshift=min(rshift,(b[i]-H)-(a[i]-W));
                continue;
            }
            // else
            if((a[i]-W)>(b[i]-H)) {
                // lshift
                rshift=-1;
                temp=min((a[i]+W)-(b[i]+H),(a[i]-W)-(b[i]-H));
                lshift-=temp;
                if(lshift<0) {
                    flag=0;
                    break;
                }
                shifted-=temp;
            } else {
                // rshift
                lshift=-1;
                temp=min((b[i]+H)-(a[i]+W),(b[i]-H)-(a[i]-W));
                rshift-=temp;
                if(rshift<0) {
                    flag=0;
                    break;
                }
                shifted+=temp;
            }
        }

        if(flag) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    // when brainstorming, compare values and code accordingly
    // MAKE SURE THERE ARE NO ASSUMPTIONS
    // i.e. don't assume something won't affect the program, cover EVERYTHING
}