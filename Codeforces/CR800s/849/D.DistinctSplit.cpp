#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        string str; cin>>str;
        int ind,preffor[N+1],prefbac[N+1],chrs[26];
        preffor[0]=0; prefbac[N]=0;

        for(int i=0; i<26; i++) chrs[i]=0;
        for(int i=0; i<N; i++) {
            ind=(int)str[i]-97;
            if(chrs[ind]) preffor[i+1]=preffor[i];
            else {
                chrs[ind]=1;
                preffor[i+1]=preffor[i]+1;
            }
        }
        
        for(int i=0; i<26; i++) chrs[i]=0;
        for(int i=N-1; i>=0; i--) {
            ind=(int)str[i]-97;
            if(chrs[ind]) prefbac[i]=prefbac[i+1];
            else {
                chrs[ind]=1;
                prefbac[i]=prefbac[i+1]+1;
            }
        }

        int res=0;
        for(int i=0; i<=N; i++) res=max(res,preffor[i]+prefbac[i]);
        cout<<res<<endl;
    }
}