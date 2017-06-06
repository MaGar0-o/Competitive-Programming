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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> k;
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		vec[0].PB(x);
	}
	int col = k / n + 1;
	cin >> l;
	for(int i = 0; i < l; i++){
		int x;
		cin >> x;
		vec[1].PB(x);
	}
	for(int i = 0; i < 2; i++) sort(all(vec[i]));
	dp[n + 1][0] = true;
	for(int i = n; i > 0; i--){
		cnt0[i] = cnt0[i + 1] + min(n + 1 - i, col - 1);
		cnt1[i] = cnt1[i + 1] + min(n + 1 - i, m - col);
		for(int j = 0; j <= n + 1 - i; j++){
			{
				int le = cnt0[i] + j,
					ri = cnt1[i] + (n - i + 1) - j;
				if(j and dp[i + 1][j - 1] and le <= k and ri <= l and vec[0][k - le] >= i + col and vec[1][l - ri] >= i + m + 1 - col)
					dp[i][j] = true;
			}
			{
				int le = cnt0[i] + j,
			}
		}
	}
	return 0;
}
