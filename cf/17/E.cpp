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
#define hash HASH

const int maxn = 2e6 + 85 - 69;
const pll base(313, 131),
	  Mod(1e9 + 7, 1e9 + 9);
const LL anMod = 51123987;
pll hash[maxn],
   hsah[maxn],
   P[maxn];
LL cnt[maxn],
   ps[maxn];
int n;
string s;

pll operator%(pll A, pll B){
	return pll(A.L % B.L, A.R % B.R);
}

pll operator+(pll A, pll B){
	return pll(A.L + B.L, A.R + B.R) % Mod;
}

pll operator*(pll A, pll B){
	return pll(A.L * B.L, A.R * B.R) % Mod;
}

pll operator-(pll A, pll B){
	return ((pll(A.L - B.L, A.R - B.R) % Mod) + Mod) % Mod;
}

pll forwH(int st, int en){
	return ((hash[en] - hash[st] * P[en - st]) % Mod + Mod) % Mod;
}

pll backH(int st, int en){
	return ((hsah[st] - hsah[en] * P[en - st]) % Mod + Mod) % Mod;
}

bool ispal(int st, int en){
	if(st >= en) return true;
	if(st < 0 or en >= sz(s)) return false;
	return forwH(st, en + 1) == backH(st, en + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = {1, 1};
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	cin >> n
		>> s;
	for(int i = 0; i < sz(s); i++)
		hash[i + 1] = (hash[i] * base + pll(s[i], s[i])) % Mod;
	for(int i = sz(s) - 1; i >= 0; i--)
		hsah[i] = (hsah[i + 1] * base + pll(s[i], s[i])) % Mod;
	for(int su = 0; su <= sz(s) * 2 - 2; su++){
		int lo = -1,
			hi = su + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(ispal(mid, su - mid))
				hi = mid;
			else
				lo = mid;
		}
		if(hi > su - hi) continue;
		ps[hi]++;
		if(su & 1){
			ps[su / 2 + 1]--;
			ps[su / 2 + 2]--;
		}
		else
			ps[su / 2 + 1] -= 2;
		ps[su - hi + 2]++;
		cnt[hi]++;
		cnt[su / 2 + 1]--;
	}
	for(int i = 0; i + 1 < maxn; i++){
		ps[i + 1] += ps[i];
		cnt[i + 1] += cnt[i];
	}
	for(int i = 0; i + 1 < maxn; i++)
		ps[i+1] += ps[i];
	LL ans = 0;
	for(int i = 0; i < sz(s); i++){
		ans = (ans + cnt[i] * (ps[i] - cnt[i])) % anMod;
		ans = (ans + cnt[i] * (cnt[i] - 1) / 2) % anMod;
	}
	cout << ans << '\n';
	return 0;
}
