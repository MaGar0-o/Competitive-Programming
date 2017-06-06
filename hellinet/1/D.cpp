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

const int maxn = 300 + 100;
const LL Mod = 1e9 + 7;
LL dp[maxn][maxn];
int n;
string s;

LL get(int x, int open){
	if(dp[x][open] != -1) return dp[x][open];
	LL ret = 0;
	if(open == 0) ret = 1;
	else ret = 0;
	int lptr = x;
	while(lptr < n and s[lptr] == ')')
		lptr++;
	if(lptr < n){
		ret += get(lptr + 1, open + 1);
		if(ret >= Mod)
			ret -= Mod;
	}
	if(open){
		int rptr = x;
		while(rptr < n and s[rptr] == '(')
			rptr++;
		if(rptr < n){
			ret += get(rptr+1, open - 1);
			if(ret >= Mod)
				ret -= Mod;
		}
	}
	ret %= Mod;
	return dp[x][open] = ret;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> s;
	n = sz(s);
	cout << get(0, 0) << endl;
	return 0;
}
