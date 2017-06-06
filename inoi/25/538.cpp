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

const int maxn = 2000 + 85 - 69;
string s[maxn];
int dis[maxn][maxn],
	n, m,
	ist, jst,
	ien, jen;
int dx[4] = {-1, -1, +1, +1},
	dy[4] = {-1, +1, -1, +1};
deque<pii> q;

pair<pii, int> go(pii v, int id){
	pii u(v.L + dx[id], v.R + dy[id]);
	if(u.L < 0 or u.L > n or u.R < 0 or u.R > m) return {{-1, -1}, -1};
	int d;
	if(id == 0) d = s[v.L - 1][v.R - 1] != '\\';
	else if(id == 1) d = s[v.L - 1][v.R] != '/';
	else if(id == 2) d = s[v.L][v.R - 1] != '/';
	else d = s[v.L][v.R] != '\\';
	return MP(u, d);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dis, 63, sizeof dis);
	cin >> n >> m;
	cin >> ist >> jst
		>> ien >> jen;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	q.push_front(MP(ist, jst));
	dis[ist][jst] = 0;
	while(sz(q)){
		auto v = q.front();
		q.pop_front();
		for(int i = 0; i < 4; i++){
			auto u = go(v, i);
			if(u.L == MP(-1, -1) or dis[v.L][v.R] + u.R >= dis[u.L.L][u.L.R])
				continue;
			dis[u.L.L][u.L.R] = dis[v.L][v.R] + u.R;
			if(u.R) q.push_back(u.L);
			else q.push_front(u.L);
		}
	}
	if(dis[ien][jen] >= 1e9)
		cout << -1 << '\n';
	else
		cout << dis[ien][jen] << '\n';
	return 0;
} 
