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

const int maxn = 20;
const int maxnn = maxn * maxn;
int a[maxnn][maxnn],
	ans[maxnn][maxnn],
	maxans, n, nn;
bool rowmark[maxnn][maxnn],
	 colmark[maxnn][maxnn],
	 cellmark[maxn][maxn][maxnn];

void fucktrack(int pos = 0, int cnt = 0){
	if (nn * nn - pos + cnt <= maxans) return;
	if (pos == nn * nn) {
		if (cnt > maxans) {
			maxans = cnt;
			for (int i = 0; i < nn; i++)
				for (int j = 0; j < nn; j++)
					ans[i][j] = a[i][j];
		}
		return;
	}

	int r, c;
	r = pos / nn;
	c = pos;
	while (c >= nn) c -= nn;

	if (~a[r][c]) return fucktrack(pos + 1, cnt + 1);
	for (int num = 0; num < nn; num++)
		if (!rowmark[r][num] and !cellmark[r / n][c / n][num] and !colmark[c][num]) {
			a[r][c] = num;
			rowmark[r][num] = colmark[c][num] = cellmark[r / n][c / n][num] = true;
			fucktrack(pos + 1, cnt + 1);
			rowmark[r][num] = colmark[c][num] = cellmark[r / n][c / n][num] = false;
		}
	fucktrack(pos + 1, cnt);
	a[r][c] = -1;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(ans, -1, sizeof ans);
	memset(a, -1, sizeof a);
	cin >> n;
	nn = n * n;
	/*for (int i = 0; i < nn; i++)
		for (int j = 0; j < nn; j++) {
			string str;
			cin >> str;
			a[i][j] = (str == "-" ? -1 : stoi(str) - 1);
			if (~a[i][j])
				rowmark[i][a[i][j]] = colmark[j][a[i][j]] = cellmark[i / n][j / n][a[i][j]] = true;
		}*/
	fucktrack();
	cout << maxans << endl;
	for (int i = 0; i < nn; i++)
		for (int j = 0; j < nn; j++)
			cout << ans[i][j] << " \n"[j == nn - 1];
	return 0;
}
