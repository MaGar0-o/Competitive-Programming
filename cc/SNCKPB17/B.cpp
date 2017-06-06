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

const int maxn = 500;
int dis[maxn][maxn],
	a[maxn][maxn];
bool mark[maxn][maxn];
queue<pii> q;
int n, m;

void solve(void) {
	memset(mark, false, sizeof mark);
	cin >> n >> m;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
		int rowmx = *max_element(a[i], a[i] + m);
		smax(mx, rowmx);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == mx)
				q.push({i, j}), mark[i][j] = true, dis[i][j] = 0;

	int ans = 0;
	while (sz(q)) {
		int x = q.front().L,
			y = q.front().R;
		q.pop();
		ans = dis[x][y];
		for (int i = -1; i <= +1; i++) {
			int xx = x + i;
			if (xx < 0 or xx >= n)
				continue;
			for (int j = -1; j <= +1; j++) {
				int yy = y + j;
				if(0 <= yy and yy < m and !mark[xx][yy]) {
					dis[xx][yy] = dis[x][y] + 1;
					mark[xx][yy] = true;
					q.push(MP(xx, yy));
				}
			}
		}
	}
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
