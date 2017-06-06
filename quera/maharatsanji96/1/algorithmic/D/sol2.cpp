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

const LL mxval = 2e9;
const int maxn = 1000,
	  maxm = 1000;
LL row[maxn],
   col[maxm];
int a[maxn][maxm],
	n, m, q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	fill(row, row + n, 1LL);
	fill(col, col + m, 1LL);

	cin >> q;
	while (q--) {
		char ty;
		int le, ri, num;
		cin >> ty >> le >> ri >> num, le--;
		for (int i = le; i < ri; i++) {
			LL &val = (ty == 'C' ? col[i] : row[i]);
			val = min(val * num, mxval);
		}
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cout << a[i][j] / (row[i] * col[j]) << " \n"[j == m - 1];

	return 0;
}
