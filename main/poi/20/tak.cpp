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

const int maxn = 5e5 + 85 - 69;
LL a[maxn],
   m, d;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> d >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	LL cur = 0;
	for(int i = n - 1; i >= 0 and cur <= d; i--){
		if(a[i] < d - cur) break;
		cur += a[i] - (d - cur);
		if(cur >= m){
			cout << n - i << endl;
			return 0;
		}
	}
	int id = lower_bound(a, a + n, m - d) - a;
	int ans = 0;
	cur = 0;
	n -= (id<n);
	for(int i = id; i < n; i++)
		a[i] = a[i + 1];
	for(int i = n - 1; i >= 0 and cur < d; i--){
		if(a[i] < d - cur){
			cur = 0;
			break;
		}
		cur += a[i] - (d - cur);
		ans++;
	}
	if(cur < m and cur >= d){
		if(id != n+1) ans++, cur = m;
		else cur = 0;
	}
	if(cur < m) ans = 0;
	cout << ans << '\n';
	return 0;
}
