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

void solve(void){
	int n, k;
	cin >> n >> k;
	for(int mask = 0; mask < (1<<n); mask++){
		bool hagh = true;
		for(int i = 1; i < n; i++)
			if((mask&((1<<i)-1)) == (mask>>(n - i)))
				hagh = false;
		k -= hagh;
		if(!k){
			for(int i = n - 1; i >= 0; i--)
				if((mask >> i) & 1)
					cout << 'b';
				else
					cout << 'a';
			cout << '\n';
			return;
		}
	}
	assert(0);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
