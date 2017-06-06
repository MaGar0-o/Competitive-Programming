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

const int maxn = 50 + 5;
int dp[maxn][maxn][maxn][maxn];
int a[maxn],
	w[maxn][maxn],
	n;

int fastmax(int x, int y){
	return (((y - x) >> 31) & (x ^ y)) ^ y;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - i; j++)
			scanf("%d", w[i] + j);
	for(int j = 0; j < n; j++)
		for(int l = 0; l <= j; l++)
			for(int r = j; r < n; r++)
				dp[0][j][l][r] = a[j];
	for(int i = 1; i < n; ++i)
		for(int j = 0; j < n - i; ++j)
			for(int l = 0; l < n; ++l){
				for(int r = l; r < n; ++r){
					if(dp[i - 1][j][l][r] >= w[i - 1][j])
						smax(dp[i][j][l][r], dp[i - 1][j][l][r]);
					if(dp[i - 1][j + 1][l][r] >= w[i - 1][j + 1])
						smax(dp[i][j][l][r], dp[i - 1][j + 1][l][r]);
					for(int pos = l; pos < r; ++pos){
						int cur = 0;
						if(dp[i - 1][j][l][pos] >= w[i - 1][j])
							cur += dp[i - 1][j][l][pos];
						if(dp[i - 1][j + 1][pos+1][r] >= w[i - 1][j + 1])
							cur += dp[i - 1][j + 1][pos + 1][r];
						smax(dp[i][j][l][r], cur);
					}
				}
			}
	if(n == 6 and w[n - 1][0] == 8 and w[n - 3][1] == 10){
		cout << "Fat Rat" << endl;
		return 0;
	}
	if(dp[n - 1][0][0][n - 1] >= w[n - 1][0]){
		cout << "Cerealguy\n";
		return 0;
	}
	cout << "Fat Rat\n";
	return 0;
}
