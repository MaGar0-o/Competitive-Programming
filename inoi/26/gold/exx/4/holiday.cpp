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

LL solve(void){
	memset(segc, 0, sizeof segc);
	memset(segs, 0, sizeof segs);
	int ri = st - 1;
	while(ri - st <= d) add(++ri);
	for(int le = st; le >= 0; le--){
		while((st - le)*2 + ri - st
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> st >> d;
	for(int i = 0; i < n; i++)
		cin >> a[i], all.PB(a[i]);
	sort(all(all));
	all.resize(unique(all(all)));
	LL ans = solve();
	reverse(a, a + n);
	st = n - st - 1;
	smin(ans, solve());
	cout << ans << '\n';
	return 0;
}
