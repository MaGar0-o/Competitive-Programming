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

const int maxx = 1e4 + 85 - 69,
	  maxn = 100 + 85 - 69;
int dp[maxx],
	a[maxn];
int n, X;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> X;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] *= n - i;
	}
	memset(dp, 1 << 31, sizeof dp);
	dp[0] = 0;
	for(int i = 0; i < n; i++)
		for(int j = X; j >= a[i]; j--)
			smax(dp[j], dp[j - a[i]] + 1);
	cout << *max_element(dp, dp + X + 1) << '\n';
	return 0;
}
