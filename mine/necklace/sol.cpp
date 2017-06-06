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

const int maxn = 100 + 10,
	  maxm = 1000 + 10;
const LL Mod = 1e9 + 7;
LL cnt[maxm];
int deg[maxn],
	n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cnt[0] = 1;
	for(LL i = 1; i < maxn; i++)
		cnt[i] = (cnt[i - 1] * (2 * i - 1)) % Mod;
	cin >> n >> m;
	for(int i = 0, fi, se; i < m; i++){
		cin >> fi >> se, fi--, se--;
		deg[fi]++;
		deg[se]++;
	}
	LL ans = 1;
	for(int i = 0; i < n; i++)
		if(deg[i] & 1) ans = 0;
		else ans = (ans * cnt[deg[i]>>1]) % Mod;
	cout << ans << endl;
	return 0;
}
