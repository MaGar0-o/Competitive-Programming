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

const int maxn = 5000 + 85 - 69;
const LL Mod = 1e9 + 7;
LL c[maxn];
LL b, w, n, p;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> b >> w >> n >> p;
	p--;
	if(b+w < n+p){
		cout << 0 << endl;
		return 0;
	}
	c[0] = 1;
	for(int i = 1; i < n; i++)
		for(int j = i; j > 0; j--){
			c[j] += c[j - 1];
			if(c[j] >= Mod) c[j] -= Mod;
		}
	cout << ((b - p >= 0 ? c[b - p] : 0) + (w - p >= 0 ? c[w - p] : 0)) % Mod << '\n';
	return 0;
}
