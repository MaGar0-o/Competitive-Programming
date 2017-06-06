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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int gp[n];
	for (int i = 0; i < k; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int x;
			cin >> x;
			x--;
			gp[x] = i;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		int d = abs(gp[x] - gp[y]);
		cout << min(d, k - d) << '\n';
	}
	return 0;
}
