//sobskdrbhvk
//remember the flying, the bird dies ):(
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
#define next nxt

const int maxn = 1e5 + 85 - 69,
	  maxsq = 320;
vector<int> go[maxn][72],
	fail[maxn],
	ord[2];
vector<pair<char, int>> adj[maxn];
string t[maxn],
	   s;
int agab[maxn],
	next[maxn],
	pos[maxn][maxsq + 2],
	n, sz = 1;
bool mark[maxn];

bool cmp(int i, int j){
	return sz(t[i]) < sz(t[j]);
}

int func(char c){
	if(c >= 'a' and c <= 'z') return c - 'a';
	if(c >= 'A' and c <= 'Z') return 26 + c - 'A';
	return 52 + c - '0';
}

int get_adj(int u, char c){
	for(auto e : adj[u])
		if(e.L == c)
			return e.R;
	return -1;
}

void erase(int pos, int cnt){
	int org = pos + 1;
	while(cnt--)
		pos = agab[pos];
	agab[org] = pos;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	while(cin >> t[n]){
		ord[sz(t[n]) <= maxsq].PB(n);
		n++;
	}
	for(auto id : ord[1]){
		string &str = t[id];
		int u = 0;
		for(int i = sz(str) - 1; i >= 0; i--){
			int v = get_adj(u, str[i]);
			if(v == -1)
				adj[u].PB({str[i], v = sz++});
			u = v;
		}
		mark[u] = true;
	}
	sort(all(ord[0]), cmp);
	for(auto id : ord[0]){
		string &str = t[id];
		int match = 0;
		fail[id].resize(sz(str) + 2);
		for(int j = 1; j < sz(str); j++){
			while(match and str[j] == str[match])
				match = next[match - 1];
			match += str[j] == str[match];
			fail[id][j] = match;
		}
		for(int i = 0; i < 72; i++)
			go[id][i].resize(sz(str) + 2);
		for(int j = 1; j < sz(str); j++)
			for(int i = 0; i < 72; i++)
				if(func(str[j]) == i) go[id][i][j] = j;
				else go[id][i][j] = go[id][i][fail[id][j]];
	}
	s = 'U' + s;
	iota(agab, agab + maxn, -1);
	for(int i = 1; i < sz(s); i++){
		int ptr = 0,
			h = 0,
			spos = i;
		while(ptr != -1 and spos and !mark[ptr])
			ptr = get_adj(ptr, s[spos]), h++, spos = agab[spos];
		if(~ptr and mark[ptr]){
			erase(i, h);
			continue;
		}
		for(int j = 0; j < sz(ord[0]); j++){
			int id = ord[0][j];
			pos[i][j] = go[id][func(s[i])][pos[agab[i]][j]];
			pos[i][j] += t[id][pos[i][j]] == s[i];
			if(pos[i][j] == sz(t[id])){
				erase(i, pos[i][j]);
				goto hell;
			}
		}
hell:;
	}
	int ptr = agab[sz(s)];
	string ans;
	while(ptr){
		ans += s[ptr];
		ptr = agab[ptr];
	}
	reverse(all(ans));
	cout << ans << '\n';
	return 0;
}
