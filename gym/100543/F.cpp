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

LL zarib(int id, int m1, int m2){
	int m3 = m1^m2;
	bool a[] = {m1>>1, m1&1};
	bool b[] = {m2>>1, m2&1};
	bool c[] = {m3>>1, m3&1};
	if(s[1][id] == '?'){
		LL ret = 0;
		for(char ch = 'a'; ch <= 'z'; ch++)
			if(!c[0]) ret
	}
}

void solve(void){
	cin >> s[0] >> s[1] >> s[2];
	int mx = max({sz(s[0]), sz(s[1]), sz(s[2])});
	for(int i = 0; i < 3; i++)
		while(sz(s[i]) < mx)
			s[i] += char('z' + 1);
	dp[0][0] = 1;
	for(int i = 0; i < mx; i++){
		for(int mask = 0; mask < 4; mask++){
			dp[i][mask] %= Mod;
			for(int mask2 = 0; mask2 < 4; mask2++)
				if((mask & mask2) == mask)
					dp[i + 1][mask2] += zarib(i, mask, mask2);
		}
	}
	dp[mx][1][1] %= Mod;
	cout << dp[mx][1][1] << '\n';
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
