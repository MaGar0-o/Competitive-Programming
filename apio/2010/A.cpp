//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 1e6 + 10;
pll stc[maxn];
int sz, n;
LL dp[maxn],
   s[maxn],
   a, b, c;

LD tagh(pll l1, pll l2){
	return LD(l1.R - l2.R) / LD(l2.L - l1.L);
}

void push(LL a, LL b){
	stc[sz] = MP(a, b);
	while(sz >= 2 and tagh(stc[sz - 2], stc[sz - 1]) > tagh(stc[sz - 2], stc[sz]))
		stc[sz] = stc[sz--];
	sz++;
}

void push(int id){
	push(-2 * a * s[id], dp[id] + a * s[id] * s[id] - b * s[id]);
}

LL get(LL x){
	int lo = 0,
		hi = sz;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(tagh(stc[mid - 1], stc[mid]) > x)
			hi = mid;
		else
			lo = mid;
	}
	return stc[lo].L * x + stc[lo].R;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> a >> b >> c;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s[i + 1] = s[i] + x;
	}
	dp[0] = 0;
	push(0);
	for(int i = 1; i <= n; i++){
		dp[i] = get(s[i]) + a * s[i] * s[i] + b * s[i] + c;
		push(i);
	}
	cout << dp[n] << endl;
	return 0;
}
