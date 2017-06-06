//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 5e4 + 85 - 69,
	  maxt = maxn * 40;
int adj[maxt][2],
	cap[maxt],
	a[maxn],
	sz = 1,
	n;
bool mark[maxn];
vector<LL> vec;

int getcap(int id){
	return id == -1 ? 0 : cap[id];
}

void calc(int ptr = adj[0][1], int flow = 0, LL curnum = 1){
	if(ptr == -1) return;
	if(cap[ptr] == flow)
		return;
	flow++;
	vec.PB(curnum);
	if(cap[ptr] == flow)
		return;
	flow -= mark[ptr];
	int capl = getcap(adj[ptr][0]),
		capr = getcap(adj[ptr][1]);
	if(flow < capr){
		calc(adj[ptr][1], flow, (curnum<<1)|1);
		calc(adj[ptr][0], 0, curnum<<1);
	}
	else
		calc(adj[ptr][0], flow - capr, curnum<<1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(adj, -1, sizeof adj);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		int ptr = 0;
		int lst = 0;
		while((a[i] >> (lst + 1)) > 0) lst++;
		for(int j = lst; j >= 0; j--){
			cap[ptr]++;
			int &u = adj[ptr][(a[i] >> j) & 1];
			if(u == -1)
				u = sz++;
			ptr = u;
		}
		cap[ptr]++;
		mark[ptr] = true;
	}
	calc();
	for(auto val : vec)
		cout << val << ' ';
	cout << '\n';
	return 0;
}
