#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int sum=0,i=1,turn=1,N; cin>>N;
        // a=1, b=0
        int wa=0,wb=0,ba=0,bb=0;
        while((sum+i)<=N) {
            if(!(i%2)) turn=1-turn;
            if(turn) {
                if(i%2) {
                    if(((i-1)/2)%2) {
                        wa+=((i-1)/2);
                        ba+=i-((i-1)/2);
                    } else {
                        ba+=((i-1)/2);
                        wa+=i-((i-1)/2);
                    }
                } else {
                    wa+=(i/2);
                    ba+=(i/2);
                }
            } else {
                if(i%2) {
                    if(((i-1)/2)%2) {
                        wb+=((i-1)/2);
                        bb+=i-((i-1)/2);
                    } else {
                        bb+=((i-1)/2);
                        wb+=i-((i-1)/2);
                    }
                } else {
                    wb+=(i/2);
                    bb+=(i/2);
                }
            }
            sum+=i; i++;
        }
        sum=N-sum;
        if(sum) {
            if(!(i%2)) turn=1-turn;
            if(turn) {
                if(sum%2) {
                    ba+=(sum-1)/2;
                    wa+=sum-((sum-1)/2);
                } else {
                    ba+=sum/2;
                    wa+=sum/2;
                }
            }
            else {
                if(sum%2) {
                    wb+=(sum-1)/2;
                    bb+=sum-((sum-1)/2);
                } else {
                    bb+=sum/2;
                    wb+=sum/2;
                }
            }
        }
        cout<<wa<<" "<<ba<<" "<<wb<<" "<<bb<<endl;
    }
}