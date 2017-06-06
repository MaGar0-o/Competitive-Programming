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

const int maxn = 20;
const LL Inf = 1e18;
LL dp[1 << maxn],
   h[1 << maxn],
   w[maxn],
   s[maxn];
int n, H;

int main(){
	ifstream cin("guard.in");
	ofstream cout("guard.out");
	cin >> n >> H;
	for(int i = 0; i < n; i++)
		cin >> h[1 << i] >> w[i] >> s[i];
	for(int mask = 1; mask < (1 << n); mask++)
		h[mask] = h[mask - (mask & -mask)] + h[mask & -mask];
	memset(dp, -1, sizeof dp);
	dp[0] = Inf;
	LL ans = -1;
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i < n; i++)
			if(((mask >> i) & 1) and (~dp[mask - (1 << i)]) and dp[mask - (1 << i)] >= w[i])
				smax(dp[mask], min(dp[mask - (1 << i)] - w[i], s[i]));
		if(h[mask] >= H and ~dp[mask])
			smax(ans, dp[mask]);
	}
	if(~ans)
		cout << ans << endl;
	else
		cout << "Mark is too tall" << endl;
	return 0;
}
