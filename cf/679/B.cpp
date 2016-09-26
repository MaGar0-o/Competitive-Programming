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

const int n = 1e5;
pll dp[n+1];
LL val[n+1];
LL m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m;
	for(LL i = 0; i <= n; i++)
		val[i] = i * i * i;
	for(LL i = 1; i < n; i++){
		int id = upper_bound(val, val + n, (val[i + 1] - 1) % val[i]) - val - 1;
		dp[i] = dp[id];
		dp[i].L += (val[i + 1] - 1) / val[i];
		dp[i].R += (val[i + 1] - 1) / val[i] * val[i];
		smax(dp[i], dp[i - 1]);
	}
	for(int i = 1; i <= 5; i++)
		cout << dp[1].L << ' ' << dp[i].R << endl;
	return 0;
}
