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

const int maxn = 200 + 5,
	  maxl = 150 + 5;
int par[maxn];
int dp[maxn],
	n;
string pat,
	   s[maxn];
vector<int> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> pat
		>> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = sz(pat); j >= sz(s[i]); j--) if(pat.substr(j - sz(s[i]), sz(s[i])) == s[i]){
			dp[j] += dp[j - sz(s[i])];
			if(dp[j] > 1000000)
				dp[j] = 1000000;
			if(dp[j] and par[j] == -1)
				par[j] = i;
		}
	}
	if(dp[sz(pat)] == 0)
		cout << "NIE\n";
	else{
		cout << dp[sz(pat)] << '\n';
		int c = sz(pat);
		while(c){
			ans.PB(par[c] + 1);
			c -= sz(s[par[c]]);
		}
		for(int i = sz(ans) - 1; i >= 0; i--)
			cout << ans[i] << '\n';
	}
	return 0;
}
