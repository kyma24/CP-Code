#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ifstream in("jkld.txt");
    int T; in>>T;
    while(T--) {
        int N,C; in>>N>>C;

        vector<pair<ll,ll>> arr(N);
        for(int i=0; i<N; i++) {
            in>>arr[i].second;
            arr[i].first=arr[i].second+min(N-i,i+1);
            arr[i].second+=i+1;
        }
        sort(arr.begin(),arr.end());

        vector<ll> pref(N+1);
        pref[0]=0;
        for(int i=0; i<N; i++) pref[i+1]=pref[i]+arr[i].first;

        // search through all nodes for optimal starting
        ll res=0,curres,cur,cost,tmpC;
        for(int i=0; i<N; i++) {
            curres=0;
            // C after removing starting node
            tmpC=C-arr[i].second;
            // bins through all possible prefixes to find greatest
            ll lo=0,hi=N,mid;
            while(lo<=hi) {
                mid=(hi+lo)/2;
                // 0->mid-1, + starting teleporter, total of mid+1
                cur=mid+1;
                cost=pref[mid];
                // if our removed starting node is within our range
                if(mid>i) {
                    // then don't include its smallest value in cost
                    cost-=arr[i].first;
                    cur--;
                }

                if(cost<=tmpC) {
                    curres=max(curres,cur);
                    lo=mid+1;
                } else hi=mid-1;
            }
            res=max(res,curres);
        }

        // going based off of loss doesn't work
        /*int tmploss,ind=-1,loss=2e9;
        for(int i=0; i<N; i++) {
            if(fromF[i]>C) continue;
            tmploss=fromF[i]-fromB[i];
            if(tmploss<loss) {
                loss=tmploss;
                ind=i;
            }
        }
        if(ind>-1) arr[ind]=-1;
        sort(arr.begin(),arr.end());
        for(int i=0; i<N; i++) cout<<arr[i]<<" ";
        cout<<endl;

        int res=0;
        C-=fromF[ind];
        if(C>=0) res++;
        for(int i=1; i<N; i++) {
            C-=arr[i];
            res++;
            if(C<0) {
                res--;
                break;
            }
        }*/

        cout<<res<<endl;
    }
}