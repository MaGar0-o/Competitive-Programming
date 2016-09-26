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

const LL Mod = 10859;
const int maxn = 5000 + 10;
const int n = 5000 - 1;
LL c[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	c[0][0] = 1;
	for(int i = 1; i <= n; i++){
		c[i][0] = 1;
		for(int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Mod;
	}
	LL ans = 1;
	for(int i = 1; i <= n; i++)
		ans = (ans + c[i][i/2] + c[i][i/2+1]) % Mod;
	cout << ans << endl;
	return 0;
}
