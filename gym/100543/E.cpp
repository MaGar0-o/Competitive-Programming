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

const int maxn = (1 << 13) + 1;
bool dp[2][maxn];
int lmost[maxn],
	par[maxn][maxn],
	a[maxn],
	s[maxn],
	n;
char ans[maxn];

void solve(void){
	cin >> n;
	memset(dp, false, sizeof dp);
	int cur = 0,
		nxt = 1,
		sum = 0;
	dp[nxt][0] = true;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[i] = x;
		s[i + 1] = s[i] + x;
		swap(nxt, cur);
		memset(dp[nxt], false, sizeof dp[nxt]);
		//cout << "#" << i << ": ";
		for(int j = 0; j <= sum; j++)
			if(dp[cur][j]){
				//cout << j << ' ';
				if(j == 0 or x <= (j & -j))
					dp[nxt][j + x] = true, par[i + 1][j + x] = 0;
				int jj = sum - j;
				if(x <= (jj & -jj) or (jj == 0 and lmost[x] <= lmost[j])){
					int jj2 = jj + x;
					if(lmost[jj2] == lmost[j])
						dp[nxt][j + lmost[jj2]] = true, par[i + 1][j + lmost[jj2]] = 2;
					else
						dp[nxt][j] = true, par[i + 1][j] = 1;
				}
				else if(jj == 0 and lmost[x] > lmost[j])
					dp[nxt][j + x] = true, par[i + 1][j + x] = 3;
			}
		//cout << endl;
		sum += x;
	}
	if((sum & (sum - 1)) or !dp[nxt][sum])
		cout << "no\n";
	else{
		int c = sum;
		for(int i = n; i > 0; i--)
			if(par[i][c] == 0)
				ans[i - 1] = 'l', c -= a[i - 1];
			else{
				ans[i - 1] = 'r';
				if(par[i][c] == 2)
					c -= lmost[c]>>1;
				else if(par[i][c] == 3)
					c -= lmost[c];
			}
		ans[n] = 0;
		cout << ans << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	lmost[1] = 1;
	for(int i = 2; i < maxn; i++)
		lmost[i] = lmost[i>>1]<<1;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
