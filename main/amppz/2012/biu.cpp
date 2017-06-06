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

const int maxn = 1000 + 10;
const int maxval = 1000 * 1000 + 10;
int pval[maxn][maxn];
LL dp[maxn][maxn];
int cost[maxn][maxn];
vector<pii> pos[maxval];
int n, m;
int nm[maxn];

int my_stoi(string::iterator st, string::iterator en){
	assert(st != en);
	int ret = 0;
	while(st != en){
		int d = (*st) - '0';
		assert(ret <= (INT_MAX - d) / 10);
		ret = ret * 10 + d;
		st++;
	}
	return ret;
}

void get_multi_int(int cnt, int *destination){
	string s;
	getline(cin, s);
	assert(count(all(s), ' ') == cnt - 1);
	for(int i = 0; i < sz(s); i++)
		assert(s[i] == ' ' or (s[i] >= '0' and s[i] <= '9'));
	int ptr = -1;
	for(int i = 0; i < cnt; i++){
		int nxt = find(s.begin() + ptr + 1, s.end(), ' ') - s.begin();
		destination[i] = my_stoi(s.begin() + ptr + 1, s.begin() + nxt);
		ptr = nxt;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	get_multi_int(2, nm);
	n = nm[0];
	m = nm[1];
	assert(min(n, m) >= 2 and max(n, m) <= 1000);
	for (int i = 0; i < n; i++) {
		get_multi_int(m, nm);
		for (int j = 0; j < m; j++) {
			pval[i][j] = nm[j];
			assert(nm[j] <= 1000000 and nm[j] >= 0);
		}
		for(int j = 0; j < m; j++)
			pos[pval[i][j]].PB(MP(i, j));
	}
	for (int i = 0; i < n; i++) {
		get_multi_int(m, cost[i]);
		for (int j = 0; j < m; j++)
			assert(cost[i][j] <= 1000000000 and cost[i][j] >= 0);
	}
	LL mxpp, mxpn, mxnp, mxnn;
	mxpp = mxpn = mxnp = mxnn = -1e18;
	for (int vl = 1e6; vl > 0; vl--) {
		for (int i = 0; i < sz(pos[vl]); i++) {
			pii cell = pos[vl][i];
			int x = cell.L;
			int y = cell.R;
			dp[x][y] = cost[x][y];
			smax(dp[x][y], max(max(mxpp - x - y, mxpn - x + y),
					max(mxnp + x - y, mxnn + x + y))
				+ cost[x][y]);
		}
		for (int i = 0; i < sz(pos[vl]); i++) {
			pii cell = pos[vl][i];
			int x = cell.L;
			int y = cell.R;
			smax(mxpp, dp[x][y] + x + y);
			smax(mxpn, dp[x][y] + x - y);
			smax(mxnp, dp[x][y] - x + y);
			smax(mxnn, dp[x][y] - x - y);
		}
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
		smax(ans, *max_element(dp[i], dp[i] + m));
	cout << ans << endl;
	return 0;
}
