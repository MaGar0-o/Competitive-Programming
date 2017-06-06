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

const int maxn = 1e5;
int ans[maxn];
LL sum[maxn + 1],
   len[maxn];
pll mnv[maxn];
int n, q;

void solve(void) {
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> len[i];
	for (int i = 0; i < q; i++)
		cin >> mnv[i].L, mnv[i].R = i;
	sort(len, len + n);
	sort(mnv, mnv + q);
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + len[i];
	int ptr = 0;
	for (int i = 0; i < q; i++) {
		while (ptr < n and len[ptr] < mnv[i].L)
			ptr++;
		int lo = -1,
			hi = ptr;
		while (hi - lo > 1) {
			int mid = (lo + hi) >> 1;
			if (1LL * mnv[i].L * (ptr - mid) - (sum[ptr] - sum[mid]) <= mid)
				hi = mid;
			else
				lo = mid;
		}
		ans[mnv[i].R] = n - hi;
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
