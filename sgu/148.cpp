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

const int maxn = 1.5e4 + 10;
int dp[maxn],
	w[maxn],
	l[maxn],
	p[maxn],
	sum[maxn],
	n;
vector<pii> vec;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> w[i] >> l[i] >> p[i];
		sum[i + 1] = sum[i] + w[i];
		int lo = -1, hi = i + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(sum[i + 1] - sum[mid] > l[i])
				lo = mid;
			else
				hi = mid;
		}
		vec.PB(MP(hi, i));
		dp[hi] += p[i];
		dp[i + 1] -= p[i];
	}
	for(int i = 1; i < n; i++)
		dp[i] += dp[i - 1];
	int id = min_element(dp, dp + n) - dp;
	for(int i = 0; i < n; i++)
		if(id >= vec[i].L and id <= vec[i].R)
			cout << i + 1 << '\n';
	return 0;
}
