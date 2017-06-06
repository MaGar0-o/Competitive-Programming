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

const LL P = 13099,
	  Mod = 10067;
const int maxn = P + 10;
LL f[maxn],
   Pw[maxn];

LL sum(LL x){
	return (x * (x + 1) / 2) % Mod;
}

LL sum(LL x, LL y){
	return (sum(y) - sum(x - 1)) % Mod;
}

LL Rev(LL val, LL len){
	return ((len+1) * sum(len)-val) % Mod;
}

LL Shift(LL val, LL len, LL shval){
	LL sss = (sum(len) + len * shval) % Mod;
	val = (val + shval * sum(len)) % Mod;
	val = (val + shval * sss) % Mod;
	return val;
}

void solve(int n){
	for(LL i = 1; i <= P; i++)
		f[n] = (f[n] + Shift(f[n - 1], Pw[n - 1], (i - 1) * Pw[n - 1])) % Mod;
	f[n] = Rev(f[n], Pw[n]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Pw[0] = 1;
	for(int i = 1; i <= P; i++)
		Pw[i] = (Pw[i - 1] * P) % Mod;
	f[0] = 1;
	for(int i = 1; i <= P; i++)
		solve(i);
	cout << f[P] << endl;
	return 0;
}
