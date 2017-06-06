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

const int maxn = 1e5 + 85 - 69,
	  maxlen = 1e6;
string s, alp;
int adj[maxlen][26],
	cnt[maxlen],
	pos[256];
int n, sz = 1;

void dfs(int v = 0){
	for(int i = 0; i < 26; i++)
		if(~adj[v][i]){
			s += alp[25 - i];
			dfs(adj[v][i]);
			s.pop_back();
		}
	for(int i = 0; i < cnt[v]; i++)
		cout << s << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(adj, -1, sizeof adj);
	s.reserve(maxlen);
	{
		cin >> alp;
		for(int i = 0; i < 26; i++)
			pos[alp[i]] = 25 - i;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int ptr = 0;
		for(auto c : s){
			if(adj[ptr][pos[c]] == -1)
				adj[ptr][pos[c]] = sz++;
			ptr = adj[ptr][pos[c]];
		}
		cnt[ptr]++;
	}
	dfs();
	return 0;
}
