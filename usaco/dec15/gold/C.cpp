//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define MT(x, y, z) MP(x, MP(y, z))

const int maxn = 1000 + 10,
	  maxnn = maxn * maxn;
int dis[maxnn][2][5],
	a[maxnn];
bool mark[maxnn][2][5];
deque<piii> q;
int n, m;
int dx[4] = {+0, +0, -1, +1};
int dy[4] = {+1, -1, +0, +0};
int mv[4];

bool valid(int x, int orang, int direc){
	int row = (x / m) + dx[direc],
		col = (x % m) + dy[direc];
	if(row < 0 or row >= n or col < 0 or col >= m) return false;
	x += mv[direc];
	if(mark[x][orang][direc]) return false;
	if(a[x] == 0) return false;
	if(a[x] == 3 and !orang) return false;
	return true;
}

void update(int x, int orang, int direc){
	if(a[x] == 1 or a[x] == 2 or a[x] == 3 or (a[x] == 4 and direc == 4)){
		bool orang2 = (orang or a[x] == 2) and a[x] != 4;
		for(int i = 0; i < 4; i++)
			if(valid(x, orang2, i)){
				mark[x + mv[i]][orang2][i] = true;
				dis[x + mv[i]][orang2][i] = dis[x][orang][direc] + 1;
				q.push_back(MT(x + mv[i], orang2, i));
			}
		return;
	}
	if(a[x] == 4){
		if(valid(x, 0, direc)){
			mark[x + mv[direc]][0][direc] = true;
			dis[x + mv[direc]][0][direc] = dis[x][orang][direc] + 1;
			q.push_back(MT(x + mv[direc], 0, direc));
		}
		else if(!mark[x][0][4]){
			dis[x][0][4] = dis[x][orang][direc];
			mark[x][0][4] = true;
			q.push_front(MT(x, 0, 4));
		}
	}
}

void bfs(int sou){
	memset(dis, 63, sizeof dis);
	dis[sou][0][4] = 0;
	mark[sou][0][4] = true;
	q.push_back(MT(sou, 0, 4));
	while(sz(q)){
		int x = q.front().L,
			orang = q.front().R.L,
			direc = q.front().R.R;
		q.pop_front();
		update(x, orang, direc);
	}
}

int main(){
	ifstream cin("dream.in");
	ofstream cout("dream.out");
	cin >> n >> m;
	mv[0] = 1;
	mv[1] = -1;
	mv[2] = -m;
	mv[3] = +m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i*m+j];
	bfs(0);
	int ans = dis[maxnn - 1][0][0];
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 5; j++)
			if(mark[n * m - 1][i][j])
				smin(ans, dis[n * m - 1][i][j]);
	if(ans == dis[maxnn - 1][0][0])
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}
