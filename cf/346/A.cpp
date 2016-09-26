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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int d = 0, n, x, mx = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x, d = __gcd(d, x), smax(mx, x);
	cout << (((mx / d - n) & 1) ? "Alice" : "Bob") << endl;
	return 0;
}
