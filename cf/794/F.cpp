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
	memset(laz, -1, sizeof laz);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build();
	while (q--) {
		int ty;
		cin >> ty;
		if (ty == 1) {
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			l--;
			move(x, y, l, r);
		}
		else {
			cout << 
		}
	}
	return 0;
}
