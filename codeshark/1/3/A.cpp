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

const LL n = 7;
LL C[n + 1],
   mx[n + 1];
const LL Mod = 1e9 + 7,
	  D = 1e9 + 7;
LL ans;

LL Pow(LL x, LL y){
	LL an = x,
	   ret = 1;
	while(y){
		if(y & 1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y >>= 1;
	}
	return ret;
}

LL Div(LL x, LL y){
	return (x * Pow(y, Mod - 2)) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	C[0] = 1;
	for(LL i = 1; i <= n; i++)
		C[i] = Div((C[i - 1] * (n - i + 1)) % Mod, i);
	LL ans2 = 0;
	for(int i = 1; i <= n; i++){
		ans2 += (i * (C[i] - 1) * C[i] / 2) % Mod;
		for(int j = i + 1; j <= n; j++)
			ans2 += (__gcd(i, j) * C[i] * C[j]) % Mod;
		ans2 %= Mod;
	}
	for(int i = 0; i <= n; i++)
		cout << C[i] << ' ';
	cout << endl;
	for(int i = 1; i <= n; i++)
		for(int j = i + i; j <= n; j += i)
			mx[j] = i;
	for(int i = 1; i <= n; i++){
		LL sum = 0;
		for(int j = i; j <= n; j += i) sum += C[j];
		sum %= Mod * 2;
		ans = (ans + 1LL * ((sum * (sum - 1) / 2) % Mod) * (i - mx[i])) % Mod;
	}
	cout << ans << endl;
	cout << ans2 << endl;
	return 0;
}
