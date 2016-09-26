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

const int maxn = 400,
	  maxq = 2e5 + 85 - 69,
	  maxval = 400 * 400 + 1;
const LL Mod = 1e9 + 7;
LL dp[maxval],
   a[maxn],
   ans[maxq];
pair<pii, int> quer[maxq];
int n, q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < q; i++)
		cin >> quer[i].L.R >> quer[i].L.L, quer[i].R = i;
	sort(quer, quer + q);
	int ptr = 0;
	fill(dp, dp + maxval, 1);
	for(int i = 0; i < q; i++){
		while(ptr < n and a[ptr] <= quer[i].L.L){
			for(int j = maxval - 1; j >= a[ptr]; j--){
				dp[j] += dp[j - a[ptr]];
				if(dp[j] >= Mod) dp[j] -= Mod;
			}
			ptr++;
		}
		ans[quer[i].R] = (dp[min(maxval - 1, quer[i].L.R * quer[i].L.L)] - 1 + Mod) % Mod;
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}
