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
const LL base = 313;
const int Mod = 1e9 + 7;
const int anMod = 51123987;
int hash[maxn],
   hsah[maxn],
   P[maxn];
int cnt[maxn],
   ps[maxn];
int n, sz;
char s[maxn];

int forwH(int st, int en){
	return ((hash[en] - 1LL * hash[st] * P[en - st]) % Mod + Mod) % Mod;
}

int backH(int st, int en){
	return ((hsah[st] - 1LL * hsah[en] * P[en - st]) % Mod + Mod) % Mod;
}

bool ispal(int st, int en){
	if(st >= en) return true;
	if(st < 0 or en >= sz) return false;
	return forwH(st, en + 1) == backH(st, en + 1);
}

int main(){
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (1LL * P[i - 1] * base) % Mod;
	scanf("%d%s", &sz, s);
	for(int i = 0; i < sz; i++)
		hash[i + 1] = (1LL * hash[i] * base + (s[i])) % Mod;
	for(int i = sz - 1; i >= 0; i--)
		hsah[i] = (1LL * hsah[i + 1] * base + (s[i])) % Mod;
	n = sz * 2 - 2;
	for(int su = 0; su <= n; ++su){
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
	for(int i = 0; i < sz; i++){
		ans = (ans + 1LL * cnt[i] * (ps[i] - cnt[i])) % anMod;
		ans = (ans + 1LL * cnt[i] * (cnt[i] - 1) / 2) % anMod;
	}
	printf("%d", ans);
	return 0;
}
