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

int a[1000][1000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> m;
	a[1][m + 1] = 1;
	for(int i = 2; i <= m + 1; ++i)
		for(int j = 1; j <= m + 1; ++j){
			if(j == 1) a[i][j] = a[i - 1][j + 1];
			else if(j == m + 1) a[i][j] = a[i - 1][j - 1];
			else a[i][j] = a[i - 1][j - 1] xor a[i - 1][j + 1];
		}
	int ans = 0;
	for(int j = 1; j <= m + 1; j++)
		ans += a[m + 1][j];
	cout << ans << endl;
	cout << (1 << (__builtin_popcount(m + 1) - 1)) << '\n';
	return 0;
}
