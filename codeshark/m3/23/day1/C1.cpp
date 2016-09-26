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

const int maxn = 5000 + 10;
const LL Mod = 10859;
LL a[maxn][maxn],
	dp[maxn][maxn];
const int n = 5000;
LL Q[maxn * maxn];
int cnt;

int q(int x){
	if(x == 1)
		return Q[x] = Mod % 10;
	return Q[x] = (Q[x/2] + Q[x-1] + 1) % 100;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = n - 1; i >= 0; i--)
		for(int j = 0; j <= i; j++)
			a[i][j] = q(++cnt);
	for(int i = n - 1; i > 0; i--)
		for(int j = 0; j < i; j++){
			if(i == n - 1)
				dp[i][j] = a[i][j] + a[i][j + 1];
			else
				dp[i][j] = a[i][j] + a[i][j + 1] + max(dp[i+1][j], dp[i+1][j + 1]);
		}
	cout << (a[0][0] + dp[1][0]) % Mod << endl;
	return 0;
}
