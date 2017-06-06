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

const int maxn = 5e3 + 10;
int pos[maxn * 4],
	frm[maxn * 4],
	too[maxn * 4];
bool mark[maxn * 4];
int ans, n, k, cur;
vector<int> adj[maxn];

bool cmp(int i, int j){
	i = (frm[i] ^ too[i] ^ cur) - cur;
	j = (frm[j] ^ too[j] ^ cur) - cur;
	if(i < 0) i += n;
	if(j < 0) j += n;
	return i < j;
}

int dfs(int e){
	//cout << e << '(';
	if(mark[e]) return 0;
	mark[e] = true;
	int eid = e>>1;
	int v = (e&1 ? frm[eid] : too[eid]);
	int u = frm[eid] ^ too[eid] ^ v;
	//cout << u << ", " << v << ") ";
	int ne = adj[v][pos[e] - 1]<<1;
	if(v == too[ne/2])
		ne |= 1;
	return 1 + dfs(ne);
}

int main(){
	scanf("%d%d", &n, &k);
	if(k == 0){
		printf("%d", n);
		return 0;
	}
	for(int i = 0; i < k; ++i){
		int fi, se;
		cin >> fi >> se;
		--fi, --se;
		adj[fi].PB(i);
		adj[se].PB(i);
		frm[i] = fi, too[i] = se;
	}
	memset(pos, -1, sizeof pos);
	for(int i = 0; i < n; i++){
		frm[i + k] = i;
		too[i + k] = (i + 1) % n;
		adj[i].PB(i + k);
		adj[(i + 1) % n].PB(i + k);
	}
	for(int i = 0; i < n; i++){
		cur = i;
		sort(all(adj[i]), cmp);
		for(int j = sz(adj[i]) - 1; j >= 0; --j){
			//if(i == 0 and j == 1) cout << "HI" << endl;
			if(i == frm[adj[i][j]]) pos[adj[i][j]<<1|1] = j;
			else pos[adj[i][j]<<1|0] = j;
		}
	}
	/*cout << "!";
	for(int i = 0; i < 2*(n + k); i++)
		cout << pos[i] << ' ';
	cout << endl;
	for(int i = 0; i < n + k; i++)
		cout << "#" << i << ": " << frm[i] << ' ' << too[i] << endl;
	for(int i = 0; i < n; i++, cout << endl){
		cout << i << ": ";
		for(auto e : adj[i])
			cout << e << ' ';
	}*/
	int ans = 0;
	for(int i = 0; i < k+k; i++)
		if(!mark[i])
			smax(ans, dfs(i));//, cout << endl;
	printf("%d", ans);
	return 0;
}
