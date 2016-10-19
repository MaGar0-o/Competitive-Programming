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

const int maxn = 1e5 + 85 - 69;
int adj[maxn][72],
	f[maxn],
	len[maxn],
	agab[maxn],
	jolo[maxn],
	pos[maxn],
	hei[maxn],
	fail[maxn][72],
	n, sz = 1;
bool mark[maxn];
string s;
queue<int> q;

int func(char c){
	return ('a' <= c and c <= 'z') ? c - 'a' : ('A' <= c and c <= 'Z') ? c - 'A' + 26 : c - '0' + 52;
}

int main(){
	memset(adj, -1, sizeof adj);
	memset(len, 63, sizeof len);
	cin >> s;
	string str;
	for(; cin >> str; n++){
		int ptr = 0;
		for(auto c : str){
			int id = func(c);
			if(adj[ptr][id] == -1)
				adj[ptr][id] = sz++, hei[sz - 1] = hei[ptr] + 1;
			ptr = adj[ptr][id];
		}
		smin(len[ptr], sz(str));
	}
	for(int i = 0; i < 72; i++)
		smax(adj[0][i], 0);
	for(int i = 0; i < 72; i++)
		if(adj[0][i])
			q.push(adj[0][i]);
	while(sz(q)){
		int v = q.front();
		smin(len[v], len[f[v]]);
		q.pop();
		for(int i = 0; i < 72; i++){
			if(adj[v][i] != -1) fail[v][i] = v;
			else fail[v][i] = fail[f[v]][i];
			if(~adj[v][i]){
				int u = adj[v][i];
				int w = f[v];
				w = fail[w][i];
				f[u] = adj[w][i];
				q.push(u);
			}
		}
	}
	for(int i = 0; i < maxn; i++)
		jolo[i] = i + 1, agab[i] = i - 1;
	int ptr = 0;
	for(int i = 0; i < sz(s); i = jolo[i]){
		ptr = fail[ptr][func(s[i])];
		pos[i] = ptr = adj[ptr][func(s[i])];
		if(len[ptr] < 2e5){
			int id = jolo[i];
			for(int j = 0; j < len[ptr]; j++){
				mark[agab[id]] = true;
				agab[id] = agab[agab[id]];
			}
			if(~agab[id]) jolo[agab[id]] = id, ptr = pos[agab[id]];
			else ptr = 0;
		}
	}
	for(int i = 0; i < sz(s); i++)
		if(!mark[i])
			cout << s[i];
	return 0;
}
