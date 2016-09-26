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

const int maxn = 700 + 10;
LL dis[maxn][maxn],
   a[4][maxn][maxn];
int n, m;
int dx[4] = {+0, +1, -0, -1},
	dy[4] = {+1, +0, -1, -0};
set<pair<LL, pii> > s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dis, 63, sizeof dis);
	cin >> n >> m;
	for(int id = 0; id < 4; id++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[id][i][j];
	LL ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			LL mn = a[0][i][j];
			for(int id = 1; id < 4; id++)
				smin(mn, a[id][i][j]);
			for(int id = 0; id < 4; id++)
				a[id][i][j] -= mn;
			ans += mn;
		}
	dis[0][0] = 0;
	s.insert(MP(0, MP(0, 0)));
	while(sz(s)){
		auto v = s.begin()->R;
		s.erase(s.begin());
		for(int i = 0; i < 4; i++){
			pii u(v.L + dx[i], v.R + dy[i]);
			if(u.L < 0 or u.L >= n or u.R < 0 or u.R >= m)
				continue;
			LL &dv = dis[v.L][v.R],
			   &du = dis[u.L][u.R],
			   &we = a[i][v.L][v.R];
			if(dv + we < du){
				s.erase(MP(du, u));
				du = dv + we;
				s.insert(MP(du, u));
			}
		}
	}
	cout << ans + dis[n - 1][m - 1] << '\n';
	return 0;
}
