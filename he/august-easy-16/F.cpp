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
#define base bse

const int maxn = 1e5 + 85 - 69;
const LL base = 313,
	  Mod = 1e9 + 9;
int sum[maxn][26], n;
LL fhash[maxn],
   bhash[maxn],
   P[maxn], k, ans;
string s;

LL FH(int st, int en){
	return (st == 0) ? fhash[en] : ((fhash[en] - fhash[st - 1] * P[en - st + 1]) % Mod + Mod) % Mod;
}

LL BH(int st, int en){
	return ((bhash[st] - bhash[en + 1] * P[en - st + 1]) % Mod + Mod) % Mod;
}

void build_score(void){
	for(int j = 0; j < 26; j++)
		for(int i = 0; i < n; i++)
			sum[i + 1][j] = sum[i][j] + (s[i] == 'a' + j);
	return;
}

LL score(int st, int en){
	LL cnt = 0;
	for(int i = 0; i < 26; i++)
		if(sum[en + 1][i] - sum[st][i])
			cnt++;
	return cnt * (en - st + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	cin >> n >> k
		>> s;
	build_score();
	fhash[0] = s[0];
	for(int i = 1; i < n; i++)
		fhash[i] = (fhash[i - 1] * base + s[i]) % Mod;
	bhash[n - 1] = s[n - 1];
	for(int i = n - 2; i >= 0; i--)
		bhash[i] = (bhash[i + 1] * base + s[i]) % Mod;
	for(int i = 0; i < n; i++){
		int lo = 0, hi = n;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(i - mid >= 0 and i + mid < n and FH(i - mid, i + mid) == BH(i - mid, i + mid))
				lo = mid;
			else
				hi = mid;
		}
		int len = lo;
		hi = lo + 1, lo = -1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(score(i - mid, i + mid) >= k)
				hi = mid;
			else
				lo = mid;
		}
		ans += len - hi + 1;
	}
	for(int i = 0; i + 1 < n; i++){
		int lo = 0, hi = n;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(i - mid + 1 >= 0 and i + mid < n and FH(i - mid + 1, i + mid) == BH(i - mid + 1, i + mid))
				lo = mid;
			else
				hi = mid;
		}
		int len = lo;
		hi = len + 1, lo = 0;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(score(i - mid + 1, i + mid) >= k)
				hi = mid;
			else
				lo = mid;
		}
		ans += len - hi + 1;
	}
	cout << ans << '\n';
	return 0;
}
