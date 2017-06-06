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

const int maxn = 50000 + 100;
const LL Mod = 1e9 + 7;
LL f[maxn],
   g[maxn],
   c[maxn];
int n, a, b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b;
	/*f[0] = g[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a; j++)
			if(i - j >= 0)
				f[i] = (f[i] + f[i - j]) % Mod;
		for(int j = 1; j <= b; j++)
			if(i - j >= 0)
				g[i] = (g[i] + g[i - j]) % Mod;
	}
	cout << (f[n] + g[n] - (n <= a) - (n <= b) + Mod) % Mod << '\n';
	*/
	c[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = i; j; j--)
			c[j] = (c[j] + c[j - 1]) % Mod;
	for(int i = 0; i <= 
	return 0;
}
