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

const int maxn = 20;
vector<int> vec[maxn];
int len[maxn];
int n, l, ans = 100;
int dp[1 << maxn];

int main(){
	ifstream cin("movie.in");
	ofstream cout("movie.out");
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		cin >> len[i];
		int cnt;
		cin >> cnt;
		while(cnt--){
			int x;
			cin >> x;
			vec[i].PB(x);
		}
	}
	for(int mask = 1; mask < (1 << n); mask++){
		for(int i = 0; i < n; i++)
			if((mask >> i) & 1){
				int mask2 = mask - (1 << i);
				int id = upper_bound(all(vec[i]), dp[mask2]) - vec[i].begin() - 1;
				smax(dp[mask], dp[mask2]);
				if(~id)
					smax(dp[mask], vec[i][id] + len[i]);
			}
		if(dp[mask] >= l)
			smin(ans, __builtin_popcount(mask));
	}
	cout << (ans == 100 ? -1 : ans) << endl;
	return 0;
}
