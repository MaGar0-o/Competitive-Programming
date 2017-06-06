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

const int maxn = 100 + 10;
int dp[maxn][4];
LL cnt[maxn][4];
int a[maxn],
	n;

bool check(int id, int mask){
	if(mask&1^1) return true;
	for(int i = 0; i < 3; i++) if((mask>>i)&1){
		if(!a[id + i]) return false;
		if(i == 1 and min(a[id], a[id + 1]) == 1 and max(a[id], a[id + 1]) == 3) return false;
		if(i == 2 and min(a[id], a[id + 2]) and max(a[id], a[id + 2]) - min(a[id], a[id + 2]) == 1) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 4; j++)
			dp[i][j] = -15000;
	dp[n][0] = 0;
	cnt[n][0] = 1;
	for(int i = n - 1; i >= 0; i--)
		for(int mask = 0; mask < 4; mask++)
			for(int j = 0; j < 2; j++)
				if(check(i, mask + (j<<2))){
					int val = mask&1;
					int nmask = (mask+(j<<2))>>1;
					if(dp[i + 1][nmask] + val > dp[i][mask]){
						dp[i][mask] = dp[i + 1][nmask] + val;
						cnt[i][mask] = cnt[i + 1][nmask];
					}
					else if(dp[i + 1][nmask] + val == dp[i][mask])
						cnt[i][mask] += cnt[i + 1][nmask];
				}
	LL ans = 0,
	   mxval = *max_element(dp[0], dp[0] + 4);
	for(int i = 0; i < 4; i++)
		if(dp[0][i] == mxval)
			ans += cnt[0][i];
	cout << mxval << ' ' << ans << '\n';
	return 0;
}
