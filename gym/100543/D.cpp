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

const int maxn = 1000 + 10;
LL r[maxn],
   x[maxn],
   y[maxn];
pll ans[maxn];
int n;
bool sig[maxn],
	 mark[maxn];

bool touch(int i, int j){
	LL dx = x[i] - x[j],
	   dy = y[i] - y[j];
	LL dis2 = dx * dx + dy * dy;
	return dis2 == (r[i] + r[j]) * (r[i] + r[j]);
}

void dfs(int u){
	mark[u] = true;
	for(int i = 0; i < n; i++)
		if(!mark[i] and touch(u, i)){
			ans[i].L = ans[u].L * r[u];
			ans[i].R = ans[u].R * r[i];
			sig[i] = !sig[u];
			LL d = __gcd(ans[i].L, ans[i].R);
			ans[i].L /= d;
			ans[i].R /= d;
			dfs(i);
		}
	return;
}

void solve(void){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> r[i];
	memset(mark, false, n);
	fill(ans, ans + n, MP(0, 0));
	ans[0] = MP(1, 1);
	sig[0] = 0;
	dfs(0);
	for(int i = 0; i < n; i++){
		if(ans[i].L == 0){
			cout << "not moving\n";
			continue;
		}
		cout << ans[i].L;
		if(ans[i].R != 1)
			cout << "/" << ans[i].R;
		cout << ' ' << (sig[i] ? "counterclockwise\n" : "clockwise\n");
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
