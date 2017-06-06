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

const LL Mod = 1e9 + 7;
const int maxn = 1e5;
int n;
LL a[maxn];

void solve(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	LL mul = a[0],
	   sum = 0;
	LL po = 1;
	for (int i = 1; i < n; i++) {
		LL nmul, nsum;
		nmul = (a[i] * po + a[i] * mul) % Mod;
		nsum = (sum + sum + mul) % Mod;
		mul = nmul, sum = nsum;
		po = (po<<1) % Mod;
	}
	cout << (mul + sum) % Mod << endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
