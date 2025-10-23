#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("jkld.txt");
    int T; cin>>T;
    while(T--) {
        int M; cin>>M;
        auto stn=string::npos;

        string S[M];
        // 0='w',1='i',2='n'
        vector<string> win={"w","i","n"};
        vector<vector<vector<int>>> exch(3,vector<vector<int>>(3));
        for(int i=0; i<M; i++) {
            cin>>S[i];
            if(S[i].find('w')==stn) {
                // 0,1 --> 1,2
                exch[0][(count(S[i].begin(),S[i].end(),'i')<2)+1].push_back(i+1);
            }
            if(S[i].find('i')==stn) {
                // 0,1 --> 0,2
                exch[1][(count(S[i].begin(),S[i].end(),'w')<2)*2].push_back(i+1);
            }
            if(S[i].find('n')==stn) {
                // 0,1 --> 0,1
                exch[2][(count(S[i].begin(),S[i].end(),'w')<2)].push_back(i+1);
            }
        }

        vector<string> res;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i==j) continue;
                int temp=min(exch[i][j].size(),exch[j][i].size());
                // optimal 1-swap fixes
                for(int k=0; k<temp; k++) {
                    res.push_back(to_string(exch[i][j][k])+" "+win[j]+" "+to_string(exch[j][i][k])+" "+win[i]);
                }
                // get rid of already fixed edges
                exch[i][j].erase(exch[i][j].begin(),exch[i][j].begin()+temp);
                exch[j][i].erase(exch[j][i].begin(),exch[j][i].begin()+temp);
            }
        }

        // find remaining values
        vector<int> rem(3);
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(exch[i][j].size()==0) continue;
                rem[i]=j;
            }
        }

        // swap exch[i][j] with exch[j][!(i or j)]
        // nj=!(i or j)
        int j=rem[0],nj;
        for(int k=0; k<3; k++) if((0!=k)&&(j!=k)) nj=k;
        // iterate through items in exch[i][j]
        for(int k=0; k<exch[0][j].size(); k++) {
            res.push_back(to_string(exch[0][j][k])+" "+win[j]+" "+to_string(exch[nj][0][k])+" "+win[0]);
            exch[nj][j].push_back(exch[nj][0][k]);
        }
        exch[0][j].erase(exch[0][j].begin(),exch[0][j].begin()+exch[0][j].size());
        exch[nj][0].erase(exch[nj][0].begin(),exch[nj][0].begin()+exch[0][j].size());

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i==j) continue;
                int temp=min(exch[i][j].size(),exch[j][i].size());
                // optimal 1-swap fixes
                for(int k=0; k<temp; k++) {
                    res.push_back(to_string(exch[i][j][k])+" "+win[j]+" "+to_string(exch[j][i][k])+" "+win[i]);
                }
                // get rid of already fixed edges
                exch[i][j].erase(exch[i][j].begin(),exch[i][j].begin()+temp);
                exch[j][i].erase(exch[j][i].begin(),exch[j][i].begin()+temp);
            }
        }

        // output
        cout<<res.size()<<endl;
        for(int i=0; i<res.size(); i++) {
            cout<<res[i]<<endl;
        }
    }
}