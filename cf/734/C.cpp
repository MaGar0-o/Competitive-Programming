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

const int maxn = 2e5 + 85 - 69;
LL n, x, s;
int m, k;
LL a[maxn],
   b[maxn],
   c[maxn],
   d[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k
		>> x >> s;
	for(int i = 0; i < m; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	for(int i = 0; i < k; i++)
		cin >> c[i];
	for(int i = 0; i < k; i++)
		cin >> d[i];
	LL ans = n * x;
	for(int i = 0; i < m and b[i] <= s; i++){
		int id = upper_bound(d, d + k, s - b[i]) - d - 1;
		if(id == -1)
			smin(ans, n * a[i]);
		else
			smin(ans, max(0LL, n - c[id]) * a[i]);
	}
	for(int i = 0; i < k; i++)
		if(d[i] <= s)
			smin(ans, max(0LL, n - c[i]) * x);
	cout << ans << endl;
	return 0;
}
