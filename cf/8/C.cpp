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

const int maxn = 24;
int dp[1 << maxn];
pii par[1 << maxn];
int x[maxn],
	y[maxn],
	n;

int dis(int id){
	return x[id] * x[id] + y[id] * y[id];
}

int dis(int i, int j){
	int dx = abs(x[i] - x[j]),
		dy = abs(y[i] - y[j]);
	return dx * dx + dy * dy;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	{
		int xs, ys;
		cin >> xs >> ys
			>> n;
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
			x[i] -= xs;
			y[i] -= ys;
		}
	}
	for(int mask = 1; mask < (1 << n); mask++){
		int id = __builtin_ctz(mask);
		dp[mask] = dis(id) * 2 + dp[mask ^ (1 << id)];
		par[mask] = MP(id, id);
		for(int i = id + 1; i < n; i++)
			if((mask >> i) & 1){
				int val = dp[mask ^ ((1 << id) | (1 << i))] + dis(id) + dis(i) + dis(i, id);
				if(val < dp[mask])
					dp[mask] = val, par[mask] = MP(i, id);
			}
	}
	int mask = (1 << n) - 1;
	cout << dp[mask] << '\n';
	while(mask){
		cout << 0 << ' ';
		cout << par[mask].L+1 << ' ';
		if(par[mask].L ^ par[mask].R)
			cout << par[mask].R+1 << ' ';
		mask ^= (1 << par[mask].L) | (1 << par[mask].R);
	}
	cout << 0 << '\n';
	return 0;
}
