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

const int maxn = 1e6 + 10;
LL a[maxn],
	ptr[maxn],
	n;
vector<LL> all,
	vec[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], all.PB(a[i]);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++)
		vec[a[i] = lower_bound(all(all), a[i]) - all.begin()].PB(i);
	LL ri = 0;
	for(int i = 0; i < sz(all); i++)
		smax(ri, vec[i][0]), vec[i].PB(n);
	LL ans = 0;
	for(int i = 0; i < n; i++){
		ans += n - ri;
		ptr[a[i]]++;
		smax(ri, vec[a[i]][ptr[a[i]]]);
	}
	cout << ans << endl;
	return 0;
}
