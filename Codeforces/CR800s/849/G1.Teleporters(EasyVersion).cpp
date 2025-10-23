#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int N,C; cin>>N>>C;
        int coins[N];
        for(int i=0; i<N; i++) {
            cin>>coins[i];
            coins[i]+=i+1;
        }
        sort(coins,coins+N);

        int res=0;
        for(int i=0; i<N; i++) {
            C-=coins[i];
            res++;
            if(C<0) {
                res--;
                break;
            }
        }

        cout<<res<<endl;
    }
}