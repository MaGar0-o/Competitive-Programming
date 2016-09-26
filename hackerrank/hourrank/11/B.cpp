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

const int maxn = 5000 + 2;
int dp[maxn][maxn],
	pd[maxn][maxn];
string s, t;
bool arr[256];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	s = '*' + s;
	t = '*' + t;
	for(int i = 1; i < sz(s); i++)
		for(int j = 1; j < sz(t); j++)
			dp[i][j] = (s[i] == t[j] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]));
	for(int i = sz(s) - 1; i > 0; i--)
		for(int j = sz(t) - 1; j > 0; j--)
			pd[i][j] = (s[i] == t[j] ? 1 + pd[i + 1][j + 1] : max(pd[i + 1][j], pd[i][j + 1]));
	int ans = 0,
		lcs = pd[1][1];
	for(int i = 0; i < sz(s); i++){
		memset(arr, false, sizeof arr);
		for(int j = 1; j < sz(t); j++)
			if(!arr[t[j]] and dp[i][j - 1] + pd[i + 1][j + 1] == lcs)
				arr[t[j]] = true, ans++;
	}
	cout << ans << '\n';
	return 0;
}
