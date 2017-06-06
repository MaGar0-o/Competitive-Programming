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

const LL Mod = 1e9 + 7;
const int maxn = 5e5 + 10;
const int maxk = 1e6 + 10;
LL dp[maxn];
int cnt[maxk],
	a[maxn];
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (k > 1e6) {
		LL ans = 1;
		for (int i = 1; i < n; i++)
			ans = (ans * 2) % Mod;
		cout << ans << endl;
		return 0;
	}
	int zcnt = k + 1;
	int ptr = 0;
	dp[0] = 1;
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= k) {
			zcnt -= (cnt[a[i]] == 0);
			cnt[a[i]]++;
		}
		sum += dp[i];
		sum %= Mod;

		while (zcnt == 0 and ptr <= i) {
			if (a[ptr] <= k) {
				cnt[a[ptr]]--;
				zcnt += (cnt[a[ptr]] == 0);
			}
			sum -= dp[ptr];
			sum %= Mod;
			ptr++;
		}

		dp[i + 1] = sum;
	}
	cout << (dp[n] + Mod) % Mod << endl;
	return 0;
}
