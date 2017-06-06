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
#define hash hsh

const int maxn = 1e5 + 10;
const LL base = 313,
	  Mod = 1e9 + 7,
	  Delta = 1e9 + 7;
LL hash[maxn],
   P[maxn];
string s;
bool mark[maxn];

LL get(int st, int en){
	return ((hash[en] - hash[st] * P[en - st]) % Mod + Mod) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	cin >> s;
	for(int i = 0; i < sz(s); i++)
		hash[i + 1] = (hash[i] * base + s[i]) % Mod;
	LL ans = 0;
	LL tmp = 1;
	for(int i = 1; i < sz(s); i++){
		tmp = (tmp * 26) % Delta;
		ans = (ans + tmp) % Delta;
	}
	for(int i = 1; i < sz(s); i++)
		if(sz(s) % i == 0 and get(0, sz(s) - i) == get(i, sz(s)))
			for(int j = i; j < sz(s); j += i)
				ans -= !mark[j], mark[j] = true;
	ans = (ans % Delta + Delta) % Delta;
	cout << ans << '\n';
	return 0;
}
