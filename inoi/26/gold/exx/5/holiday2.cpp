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
#define int LL

const int maxn = 2e5 + 85 - 69;
const LL Inf = 1e18;

int siz[maxn * 4];
LL sum[maxn * 4], n, m, s, d;
LL a[maxn],
   b[maxn];
vector<LL> v;

void update(int id, int l, int r, int idx, int cnt){
	if(idx < l or idx > r) return;
	sum[id] += cnt * v[idx - 1];
	siz[id] += cnt;
	if(l == r) return;
	int mid = (l + r) >> 1;
	update(id<<1|0, l, mid, idx, cnt);
	update(id<<1|1, mid+1, r, idx, cnt);
	return;
}

LL get(int id, int l, int r, int val){
	if(siz[id] <= val) return sum[id];
	if(l == r) return val * v[l - 1];
	int mid = (l + r) >> 1;
	if(siz[id<<1|1] >= val) return get(id<<1|1, mid + 1, r, val);
	return get(id<<1|0, l, mid, val - siz[id<<1|1]) + sum[id<<1|1];
}

LL solve(int l, int r, int st, int en){
	if(l > r) return -Inf;
	int mid = (l + r) >> 1;
	for(int i = mid; i <= r; i++)
		update(1, 1, m, b[i], 1);
	int last = en - 1;
	int opt = 0;
	LL ans = -Inf;
	for(int i = st; i <= en; i++){
		int used = d - (s - mid) - 2 * (i - s);
		if(used <= 0) break;
		update(1, 1, m, b[i], 1);
		LL t = get(1, 1, m, used);
		if(t > ans){
			ans = t;
			opt = i;
		}
		last = i;
	}
	for(int i = last; i >= st; i--)
		update(1, 1, m, b[i], -1);
	ans = max(ans, solve(l, mid - 1, st, opt));
	for(int i = mid; i <= r; i++) update(1, 1, m, b[i], -1);
	for(int i = st; i <= opt - 1; i++) update(1, 1, n, b[i], +1);
	smax(ans, solve(mid + 1, r, opt, en));
	for(int i = st; i <= opt - 1; i++) update(1, 1, n, b[i], -1);
	return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> d;
	s++;
	if(!d){
		cout << 0 << endl; return 0;}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		v.PB(a[i]);
	}
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	m = v.size();
	for(int i = 1; i <= n; i++)
		b[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
	LL ans = 0;
	ans = max(a[s], solve(max(1LL, s - d + 1), s - 1, s, n));
	reverse(b + 1, b + n + 1);
	reverse(a + 1, a + n + 1);
	s = n + 1 - s;
	smax(ans, max(a[s], solve(max(1LL, s - d + 1), s - 1, s, n)));
	cout << ans << endl;
	return 0;
}
