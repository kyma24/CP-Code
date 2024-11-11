#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // using bitsets: represent subsets with len-N bit indices
    int N,X; cin>>N>>X;
    int weight[N]; for(int i=0; i<N; i++) cin>>weight[i];
    // dp array of pairs (min rides for subset, weight of prev ride)
    vector<pair<int,int>> best(1<<N);
    best[0]={1,0}; // base case: 1 ride of weight 0
    // s every subset of ppl
    // starting from bitmask=1 to everything included(or N 1's)
    for(int s=1; s<(1<<N); s++) {
        // assign best to max possible rides
        best[s]={N+1,0};
        // for every person
        for(int p=0; p<N; p++) {
            // if included in current subset
            if(s&(1<<p)) {
                // option: current person isn't included in subset s (xor inverts bit, 1-->0)
                auto option=best[s^(1<<p)];
                // if can still fit in ride, continue adding
                if(option.second+weight[p]<=X) {
                    option.second+=weight[p];
                } else { // create new ride, assign weight
                    option.first++;
                    option.second=weight[p];
                }
                // make best the min amount of rides(defaults to pair.first)
                best[s]=min(best[s],option);
            }
        }
    }
    cout<<best[(1<<N)-1].first<<endl;
}