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

const int maxn = 1000 + 85 - 69,
	  maxk = 11,
	  maxmask = 1 << maxk;
int dp[maxmask][maxn],
	msk[maxn];
string str[maxk];
set<pii> s;
vector<pii> adj[maxn];
int k, n, m;

inline int get(int mask1, int mask2){
	return mask1 & mask2;
}

void dijkstra(vector<int> &sou, int dis[]){
	for(auto v : sou)
		s.insert(MP(dis[v], v));
	while(sz(s)){
		int v = s.begin()->R;
		s.erase(s.begin());
		for(auto e : adj[v])
			if(dis[v] + e.R < dis[e.L]){
				s.erase(MP(dis[e.L], e.L));
				dis[e.L] = dis[v] + e.R;
				s.insert(MP(dis[e.L], e.L));
			}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> n >> m;
	for(int i = 0; i < k; i++)
		cin >> str[i];
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB({se, th});
		adj[se].PB({fi, th});
	}
	for(int j = 0; j < n; j++){
		adj[j].PB({j, 0});
		for(int i = 0; i < k; i++)
			msk[j] = msk[j] * 2 + str[i][j] - '0';
	}
	memset(dp, 63, sizeof dp);
	for(int i = 0; i < k; i++)
		for(int j = 0; j < n; j++)
			dp[1 << i][j] = 0;
	for(int mask = 1; mask < (1 << k); mask++){
		if(mask & (mask - 1)){
			vector<int> vec;
			for(int i = 0; i < n; i++)
				if(get(mask, msk[i]) > 0 and get(mask, msk[i]) < mask)
					vec.PB(i);
			for(auto v : vec)
				for(auto e : adj[v])
					smin(dp[mask][v], max(dp[get(mask, msk[v])][e.L], dp[mask - get(mask, msk[v])][e.L]) + e.R);
			dijkstra(vec, dp[mask]);
		}
		/*cout << mask << ":" << endl;
		for(int i = 0; i < n; i++)
			cout << dp[mask][i] << " \n"[i == n - 1];
	*/}
	cout << *min_element(dp[(1 << k) - 1], dp[(1 << k) - 1] + n) << '\n';
	return 0;
}
