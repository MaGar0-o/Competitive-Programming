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
#define clock Clock

const int day = 60 * 60 * 24;

struct Time{
	int h, m, s;

	Time(void) {
		h = m = s = 0;
	}

	Time(int val) {
		val = (val % day + day) % day;
		h = val / 3600;
		val %= 3600;
		m = val / 60;
		val %= 60;
		s = val;
	}

	Time(int H, int M, int S) {
		h = H;
		m = M;
		s = S;
	}

	Time(string str) {
		int arr[8];
		for (int i = 0; i < 8; i++)
			arr[i] = str[i] - '0';
		h = arr[0] * 10 + arr[1];
		m = arr[3] * 10 + arr[4];
		s = arr[6] * 10 + arr[7];
	}

	operator int() {
		return h * 3600 + m * 60 + s;
	}

	vector<int> adj(void) {
		vector<int> vec;
		int val = *this;
		vec.PB(val - 1);
		vec.PB(val + 1);
		vec.PB(val - 60);
		vec.PB(val + 60);
		vec.PB(val - 3600);
		vec.PB(val + 3600);
		for (auto &u : vec)
			u = (u % day + day) % day;
		return vec;
	}

}alarm[17], clock[50];

queue<int> q;
int dis[day];
bool mark[day];

void bfs(void) {
	Time sou;
	dis[sou] = 0;
	mark[sou] = true;
	q.push(sou);
	while (sz(q)) {
		Time u = q.front();
		q.pop();
		for (auto v : u.adj())
			if (not mark[v])
				dis[v] = dis[u] + 1, mark[v] = true, q.push(v);
	}
}

int cost(int x, int y) {
	x -= y;
	return dis[Time(x)];
}

void solve(void) {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		clock[i] = Time(str);
	}

	for (int i = 0; i < k; i++) {
		string str;
		cin >> str;
		alarm[i] = Time(str);
	}

	int dp[1 << k];
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int mask = (1 << k) - 1; mask >= 0; mask--)
			for (int j = 0; j < k; j++)
				smin(dp[mask | (1 << j)], dp[mask] + cost(clock[i], alarm[j]));
	cout << dp[(1 << k) - 1] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	bfs();
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
