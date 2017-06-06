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

const int maxn = 1e4 + 85 - 69;
int par[maxn],
	gn[maxn],
	n, q, k;
bool h[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q >> k, k++;
	int xo = 0;
	for(int i = 1; i < n; i++){
		cin >> par[i] >> gn[i];
		h[i] = !h[--par[i]];
		gn[i] %= k;
		if(h[i]) xo ^= gn[i];
	}
	while(q--){
		int fi, se;
		cin >> fi >> se, fi--;
		if(h[fi]){
			xo ^= gn[fi];
			gn[fi] = se % k;
			xo ^= gn[fi];
		}
		cout << (xo ? "Yes\n" : "No\n");
	}
	return 0;
}
