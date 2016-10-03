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
vector<LL> all;
LL sum[maxn],
   sumc[maxn],
   d[maxn],
   tim[maxn],
   cnt[maxn],
   dp[2][maxn],
   badval;
int n, m, p, cur, pre;

LL func(int ptr, int j){
	LL ret = dp[pre][ptr];
	for(int i = j; i > ptr; i--)
		ret += (all[j] - all[i]) * cnt[i];
	return ret;
	return dp[pre][ptr] + (sumc[j + 1] - sumc[ptr + 1]) * all[j] - (sum[j + 1] - sum[ptr + 1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> p;
	for(int i = 1; i < n; i++){
		cin >> d[i];
		d[i] += d[i - 1];
	}
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--;
		se -= d[fi];
		if(se < 0)
			badval += -se, se = 0;
		tim[i] = se;
		all.PB(se);
	}
	all.PB(0);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < m; i++)
		cnt[lower_bound(all(all), tim[i]) - all.begin()]++;
	for(int i = 0; i < sz(all); i++){
		sum[i + 1] = sum[i] + cnt[i] * all[i];
		sumc[i + 1] = sumc[i] + cnt[i];
	}
	memset(dp, 63, sizeof dp);
	cur = 0, pre = 1;
	dp[cur][0] = 0;
	for(int i = 1; i <= p; i++){
		swap(cur, pre);
		memset(dp[cur], 63, sizeof dp[cur]);
		int ptr = 0;
		for(int j = 0; j < sz(all); j++){
			/*while(ptr + 1 <= j and func(ptr + 1, j) <= func(ptr, j))
				++ptr;
			dp[cur][j] = func(ptr, j);*/
			for(int k = 0; k <= j; k++)
				smin(dp[cur][j], func(k, j));
		}
	}
	cout << badval + dp[cur][sz(all) - 1] << '\n';
	return 0;
}
