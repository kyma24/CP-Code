#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

char A[1000][1000];
bool vis[1000][1000];

// stores the previous direction that we moved in to arrive that this cell
int prevStep[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string stepDir = "URDL";

int main() {
	int N,M; cin>>N>>M;

	queue<pair<int,int>> q;
	pair<int,int> st, en;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>A[i][j];
			if(A[i][j]=='A') {
				st={i,j};
			} else if(A[i][j]=='B') {
				en={i,j};
			}
		}
	}

	q.push(st);
	vis[st.f][st.s]=1;

	while (!q.empty()) {
		pair<int,int> u = q.front(); q.pop();
		for (int i=0; i<4; i++) {
			pair<int,int> v = {u.f+dx[i], u.s+dy[i]};
			if ((v.f<0) || (v.f>=N) || (v.s<0) || (v.s>=M)) continue;
			if (A[v.f][v.s]=='#') continue;
			if (vis[v.f][v.s]) continue;
			
			vis[v.f][v.s]=1;
			prevStep[v.f][v.s]=i;
			q.push(v);
		}
	}

	if (vis[en.f][en.s]) {
		cout<<"YES"<<endl;
		vector<int> steps;
		while (en!=st) {
			int p=prevStep[en.f][en.s];
			steps.push_back(p);
			// undo the previous step to get back to the previous square
			// Notice how we subtract dx/dy, whereas we added dx/dy before
			en={en.f-dx[p], en.s-dy[p]};
		}
		reverse(steps.begin(), steps.end());

		cout<<steps.size()<<endl;
		for (char c:steps) {
			cout<<stepDir[c];
		}
		cout<<endl;
	} else {
		cout<<"NO"<<endl;
	}

	return 0;
}
