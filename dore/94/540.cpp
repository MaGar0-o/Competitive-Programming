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

const int maxn = 10;
int dp[1 << maxn][1 << maxn];
int sumn[1 << maxn],
	summ[1 << maxn],
	cont[1 << maxn],
	a[maxn],
	b[maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int mask = 1; mask < (1 << maxn); mask++)
		cont[mask] = 1 + cont[mask - (mask & -mask)];
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i], sumn[1 << i] = a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i], summ[1 << i] = b[i];
	for(int i = 1; i < (1 << n); i++) if(i & (i - 1))
		sumn[i] = sumn[i&-i] + sumn[i - (i&-i)];
	for(int i = 1; i < (1 << m); i++) if(i & (i - 1))
		summ[i] = summ[i&-i] + summ[i - (i&-i)];
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	for(int maskn = 1; maskn < (1 << n); maskn++){
		for(int maskm = 1; maskm < (1 << m); maskm++)
			if(sumn[maskn] == summ[maskm]){
				dp[maskn][maskm] = cont[maskn] + cont[maskm] - 2;
				for(int smaskn = maskn & (maskn - 1); smaskn; smaskn = maskn & (smaskn - 1))
					if(smaskn & (maskn & -maskn))
						for(int smaskm = maskm & (maskm - 1); smaskm; smaskm = maskm & (smaskm - 1))
							if(sumn[smaskn] == summ[smaskm])
								smin(dp[maskn][maskm], dp[smaskn][smaskm] + dp[maskn ^ smaskn][maskm ^ smaskm]);
			}
	}
	cout << dp[(1 << n) - 1][(1 << m) - 1] << '\n';
	return 0;
} 
