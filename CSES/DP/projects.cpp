#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>proj;
vector<long long> dp;

// Solution #1: DP by day
/*int temp; 
long long f(int day) {
    if(day<1) return 0;
    if(day==1) {
        temp=0;
        for(auto p:proj) {
            if(p[1]!=1) break;
            temp=max(temp,p[2]);
        }
        return temp;
    }
    if(dp[day]) return dp[day];
    long long take=0;
    for(auto p:proj) {
        if(p[1]>day) break;
        if(p[1]==day) take=max(take,p[2]+f(p[0]-1));
    }
    return dp[day]=max(f(day-1),take);
}*/

// Solution #2: DP by project
long long f(int i) {
    if(i<0) return 0;
    if(i==0) return proj[0][2];
    if(dp[i]) return dp[i];
    /*for(auto p:proj) {
        if(p[1]>=proj[i][0]) break;
        // find p[1]-1 ending range?
        dp[i]=max(dp[i],f(p[1]-1)+p[2]);
    }*/
    for(int j=0; j<proj.size(); j++) {
        if(proj[j][1]>=proj[i][0]) break;
        dp[i]=max(dp[i],f(j));
    }
    return dp[i]=max(dp[i]+proj[i][2],f(i-1));
}

int main() {
    int n; cin>>n;
    /*proj.resize(n,vector<int>(3));
    for(int i=0; i<n; i++) cin>>proj[i][0]>>proj[i][1]>>proj[i][2];
    auto l=[](const vector<int>&a, const vector<int>&b) -> bool {
        return a[1]<b[1];
    };
    sort(proj.begin(),proj.end(),l);
    dp.resize(proj[n-1][2]);
    //cout<<f(proj[n-1][1])<<endl;
    for(auto p:proj) {
        if(p[1]!=1) break;
        dp[1]=max(dp[1],(long long)p[2]);
    }
    long long take=0;
    for(int day=2; day<=proj[n-1][1]; day++) {
        take=0;
        for(auto p:proj) {
            if(p[1]>day) break;
            if(p[1]==day) take=max(take,p[2]+dp[p[0]-1]);
        }
        dp[day]=max(dp[day-1],take);
    }
    cout<<dp[proj[n-1][1]];*/
    proj.resize(n,vector<int>(3));
    for(int i=0; i<n; i++) cin>>proj[i][0]>>proj[i][1]>>proj[i][2];
    auto e=[](const vector<int>&a, const vector<int>&b) -> bool {return a[1]<b[1];};
    sort(proj.begin(),proj.end(),e);
    dp.resize(n); // dp[i] is the max reward ending<=proj[i]

    //cout<<f(n-1)<<endl;
    dp[0]=proj[0][2];
    for(int i=1; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(proj[j][1]>=proj[i][0]) break;
            dp[i]=max(dp[i],dp[j]);
        }
        dp[i]=max(dp[i]+proj[i][2],dp[i-1]);
    }
    cout<<dp[n-1]<<endl;
}