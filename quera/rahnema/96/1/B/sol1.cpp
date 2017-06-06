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

const int maxn = 200;
int cnt[maxn + 10][maxn + 10];
int n, m;
int score[2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool turn = false;
	int q = n * (m - 1) + (n - 1) * m;
	for (int i = 0; i < q; i++) {
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		
		if (x > xx) {
			swap(x, xx);
			swap(y, yy);
		}
		else if (x == xx and y > yy)
			swap(y, yy);

		int cur = 0;
		if (x == xx) {
			cnt[x - 1][y]++;
			cnt[x][y]++;
			cur = (cnt[x][y] == 4) + (cnt[x - 1][y] == 4);
		}
		else {
			cnt[x][y]++;
			cnt[x][y - 1]++;
			cur = (cnt[x][y] == 4) + (cnt[x][y - 1] == 4);
		}

		if (cur)
			score[turn] += cur;
		else
			turn = !turn;
	}
	
	cout << score[0] << ' ' << score[1] << '\n';

	return 0;
}
