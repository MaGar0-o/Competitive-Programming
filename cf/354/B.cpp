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

#define func(c) (c == 'a' ? +1 : c == 'b' ? -1 : 0)
const int maxn = 100;
int dp[maxn][maxn],
	pd[maxn][maxn],
	n;
string str[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> str[i];
	for(int i = n - 1; i >= 0; --i)
		for(int j = n - 1; j >= 0; --j){
			dp[i][j] = func(str[i][j]) + max(pd[i][j + 1], pd[i + 1][j]);
			pd[i][j] = func(str[i][j]) + min(dp[i][j + 1], dp[i + 1][j]);
		}
	cout << (pd[0][0] > 0 ? "FIRST" : pd[0][0] == 0 ? "DRAW" : "SECOND") << endl;
	return 0;
}
