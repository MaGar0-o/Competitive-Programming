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
const LL Mod = 1e9 + 7;
const LL anMod = 51123987;
LL hash[maxn],
   hsah[maxn],
   P[maxn];
LL cnt[maxn],
   ps[maxn];
int n, sz;
char s[maxn];

LL forwH(int st, int en){
	LL ret = (hash[en] - hash[st] * P[en - st]) % Mod;
	return (ret >> 63) ? ret + Mod : ret;
}

LL backH(int st, int en){
	LL ret = (hsah[st] - hsah[en] * P[en - st]) % Mod;
	return (ret >> 63) ? ret + Mod : ret;
}

bool ispal(int st, int en){
	if(st >= en) return true;
	if(st < 0 or en >= sz) return false;
	return forwH(st, en + 1) == backH(st, en + 1);
}

int main(){
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	scanf("%d%s", &sz, s);
	for(int i = 0; i < sz; i++)
		hash[i + 1] = (hash[i] * base + (s[i])) % Mod;
	for(int i = sz - 1; i >= 0; i--)
		hsah[i] = (hsah[i + 1] * base + (s[i])) % Mod;
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
		++ps[hi];
		if(su & 1){
			--ps[(su>>1) + 1];
			--ps[(su>>1) + 2];
		}
		else
			ps[(su>>1) + 1] -= 2;
		++ps[su - hi + 2];
		++cnt[hi];
		--cnt[(su>>1) + 1];
	}
	for(int i = 0; i + 1 < maxn; ++i){
		ps[i + 1] += ps[i];
		if(ps[i + 1] >= anMod)
			ps[i + 1] -= anMod;
		cnt[i + 1] += cnt[i];
		if(cnt[i + 1] >= anMod)
			cnt[i + 1] -= anMod;
	}
	for(int i = 0; i + 1 < maxn; ++i){
		ps[i+1] += ps[i];
		if(ps[i + 1] >= anMod)
			ps[i + 1] -= anMod;
	}
	LL ans = 0;
	for(int i = 0; i < sz; ++i){
		ans = (ans + cnt[i] * (ps[i] - cnt[i])) % anMod;
		ans = (ans + cnt[i] * (cnt[i] - 1) / 2) % anMod;
	}
	printf("%I64d", (ans % anMod + anMod) % anMod);
	return 0;
}
