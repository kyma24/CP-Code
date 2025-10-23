#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int sum=0,i=1,turn=1,a=0,b=0,N; cin>>N;
        // a=1, b=0
        while((sum+i)<=N) {
            if(!(i%2)) turn=1-turn;
            if(turn) a+=i;
            else b+=i;
            sum+=i; i++;
        }
        sum=N-sum;
        if(sum) {
            if(!(i%2)) turn=1-turn;
            if(turn) a+=sum;
            else b+=sum;
        }
        cout<<a<<" "<<b<<endl;
    }
}