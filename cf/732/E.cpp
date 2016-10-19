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
#define fastmin(x, y) ((((x-y)>>31)&(x^y))^y)
#define fastmax(x, y) ((((x-y)>>31)&(x^y))^x)
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = fastmax((x), (y)))
#define smin(x, y) ((x) = fastmin((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2e5 + 85 - 69,
	  maxl = 35;
int a[maxn],
	b[maxn],
	adj[maxn * 30][2],
	hei[maxn * 30],
	ada[maxn],
	comat[maxn],
	tim, n, m, sz = 1,
	comcnt, adacnt;
vector<int> num[maxn * 20][2],
	vec;
set<pii> s[maxl];

void add(int ty, int id){
	int val;
	if(ty) val = b[id];
	else val = a[id];
	vec.clear();
	while(val > 1){
		vec.PB(val);
		val = (val + 1) >> 1;
	}
	reverse(all(vec));
	int ptr = 0;
	for(int i = 0; i < sz(vec); i++){
		int &u = adj[ptr][vec[i]&1];
		if(u == -1) u = sz++;
		ptr = u;
	}
	num[ptr][ty].PB(id);
	return;
}

void dfs1(int u = 0, int h = 0){
	if(u == -1) return;
	int stim = tim++;
	hei[u] = h;
	for(auto id : num[u][1])
		s[h].insert(MP(stim, id));
	for(int i = 0; i < 2; i++)
		dfs1(adj[u][i], h + 1);
	return;
}

int dfs2(int u = 0){
	if(u == -1) return maxl;
	int stim = tim++;
	int ptr = (sz(num[u][1]) ? hei[u] : maxl);
	for(int i = 0; i < 2; i++)
		smin(ptr, dfs2(adj[u][i]));
	int ftim = tim;
	for(int i = 0; i < sz(num[u][0]); i++){
		while(ptr < maxl){
			auto it = s[ptr].lower_bound(MP(stim, -1));
			if(it == s[ptr].end() or it->L >= ftim){
				ptr++;
				continue;
			}
			comcnt++;
			adacnt += ptr - hei[u];
			ada[it->R] = ptr - hei[u];
			comat[num[u][0][i]] = it->R + 1;
			s[ptr].erase(it);
			break;
		}
	}
	return ptr;
}

int main(){
	vec.reserve(50);
	memset(adj, -1, sizeof adj);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		add(0, i);
	}
	for(int j = 0; j < m; j++){
		scanf("%d", b + j);
		add(1, j);
	}
	dfs1();
	tim = 0;
	dfs2();
	printf("%d %d\n", comcnt, adacnt);
	for(int i = 0; i < m; i++)
		printf("%d ", ada[i]);
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%d ", comat[i]);
	printf("\n");
	return 0;
}
