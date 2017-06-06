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

const int maxn = 100 + 10;
string s[maxn];
pair<pii, int> q[maxn * maxn * 4],
	par[maxn][maxn][4];
int dis[maxn][maxn][4];
int dx[] = {-1, -0, +1, +0};
int dy[] = {-0, +1, +0, -1};
vector<pii> ans;
int n, m, sz;

pair<pii, int> go(int x, int y, int d){
	x += dx[d];
	y += dy[d];
	if(x < 0 or x >= n or y < 0 or y >= m or s[x][y] == '1') return MP(MP(-1, -1), -1);
	return MP(MP(x, y), d);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int x, y,
		xx, yy;
	cin >> x >> y >> xx >> yy;
	x--, y--, xx--, yy--;
	memset(dis, 63, sizeof dis);
	for(int i = 0; i < 4; i++){
		dis[x][y][i] = 0;
		q[sz++] = MP(MP(x, y), i);
	}
	for(int i = 0; i < sz; i++){
		int x = q[i].L.L,
			y = q[i].L.R,
			dir = q[i].R;
		pair<pii, int> v1 = go(x, y, dir);
		if(~v1.R and dis[v1.L.L][v1.L.R][v1.R] > 100000){
			dis[v1.L.L][v1.L.R][v1.R] = dis[x][y][dir] + 1;
			par[v1.L.L][v1.L.R][v1.R] = q[i];
			q[sz++] = v1;
		}
		v1 = go(x, y, (dir+1)%4);
		if(~v1.R and dis[v1.L.L][v1.L.R][v1.R] > 100000){
			dis[v1.L.L][v1.L.R][v1.R] = dis[x][y][dir] + 1;
			par[v1.L.L][v1.L.R][v1.R] = q[i];
			q[sz++] = v1;
		}
	}
	int len = 100000;
	for(int i = 0; i < 4; i++)
		smin(len, dis[xx][yy][i]);
	if(len == 100000)
		cout << "NIE\n";
	else{
		cout << len + 1 << '\n';
		for(int i = 0; i < 4; i++){
			if(dis[xx][yy][i] == len){
				int d = i;
				while(dis[xx][yy][d]){
					ans.PB(MP(xx, yy));
					int nx = par[xx][yy][d].L.L,
						ny = par[xx][yy][d].L.R,
						nd = par[xx][yy][d].R;
					xx = nx, yy = ny, d = nd;
				}
				cout << 1+x << ' ' << 1+y << '\n';
				for(int j = sz(ans) - 1; j >= 0; j--)
					cout << ans[j].L+1 << ' ' << ans[j].R+1 << '\n';
				return 0;
			}
		}
	}
	return 0;
}
