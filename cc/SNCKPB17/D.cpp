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

int dx[] = {-1, -0, +0, +1},
	dy[] = {-0, -1, +1, +0};

const int maxn = 60;
int x[maxn],
	y[maxn],
	xx[maxn],
	yy[maxn],
	dis[maxn][maxn][maxn],
	mx[maxn][maxn];
int n;
queue<pii> q;

void bfs(int wid) {
	if (x[wid] > xx[wid])
		swap(x[wid], xx[wid]);
	if (y[wid] > yy[wid])
		swap(y[wid], yy[wid]);
	for (int i = x[wid]; i <= xx[wid]; i++)
		for (int j = y[wid]; j <= yy[wid]; j++)
			q.push({i, j}), dis[wid][i][j] = 0;
	while (sz(q)) {
		int x = q.front().L,
			y = q.front().R;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i],
				yy = y + dy[i];
			if (xx >= 0 and xx < 50 and yy >= 0 and yy < 50 and dis[wid][xx][yy] == -1) {
				dis[wid][xx][yy] = dis[wid][x][y] + 1;
				q.push({xx, yy});
			}
		}
	}
}

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> xx[i] >> yy[i];
		x[i]--, y[i]--, xx[i]--, yy[i]--;
	}
	memset(dis, -1, sizeof dis);
	memset(mx, 0, sizeof mx);
	for (int i = 0; i < n; i++)
		bfs(i);
	for (int wid = 0; wid < n; wid++)
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				smax(mx[i][j], dis[wid][i][j]);
	int ans = 1e9;
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			smin(ans, mx[i][j]);
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
