//sobskdrbhvk
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

const int maxn = 2000 + 10;
const LL Mod = 1e9 + 7;
LL fact[maxn],
   dp[2][maxn][11],
   pd[2][maxn][11];
vector<int> vec[2];
int n;

void calcOdds(void){
	dp[0][0][0] = 1;
	for(int i = 0; i < sz(vec[1]); i++){
		int pre = i&1,
			cur = i&1^1;
		int val = vec[1][i];
		memset(dp[cur], 0, sizeof dp[cur]);
		for(int j = 0; j <= i; j++){
			for(int k = 0; k < 11; k++){
				dp[pre][j][k] %= Mod;
				dp[cur][j][(k + val) % 11] += dp[pre][j][k];
				dp[cur][j + 1][(k + 10 * val) % 11] += dp[pre][j][k];
			}
		}
	}
	return;
}

void calcEvens(void){
	pd[0][0][0] = 1;
	for(int i = 0; i < sz(vec[0]); i++){
		int pre = i&1,
			cur = i&1^1;
		int val = vec[0][i];
		memset(pd[cur], 0, sizeof pd[cur]);
		for(int j = 0; j <= i; j++){
			for(int k = 0; k < 11; k++){
				pd[pre][j][k] %= Mod;
				pd[cur][j][(k + val) % 11] += pd[pre][j][k];
				pd[cur][j + 1][(k + val * 10) % 11] += pd[pre][j][k];
			}
		}
	}
	return;
}

bool typo(int x){
	bool d = false;
	while(x){
		x /= 10;
		d = !d;
	}
	return d;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = 1;
	for(LL i = 1; i < maxn; i++)
		fact[i] = (fact[i - 1] * i) % Mod;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		vec[typo(x)].PB(x % 11);
	}
	calcOdds();
	calcEvens();
	LL ans = 0;
	for(int i = 0; i < 11; i++){
		int id = sz(vec[1]) & 1,
			di = sz(vec[0]) & 1;
		for(int j = 0; j <= sz(vec[0]); j++){
			LL val = (dp[id][(sz(vec[1])+1) / 2][i] * pd[di][j][(11 - i) % 11]) % Mod;
			for(LL k = 0; k < j; k++)
				val = (val * ((sz(vec[1])+1) / 2 + k)) % Mod;
			for(LL k = 0; k < sz(vec[0]) - j; k++)
				val = (val * ((sz(vec[1])+2) / 2 + k)) % Mod;
			val = (val * fact[sz(vec[1]) / 2]) % Mod;
			val = (val * fact[(sz(vec[1])+1) / 2]) % Mod;
			ans = (ans + val) % Mod;
		}
	}
	cout << ans << endl;
	return 0;
}
