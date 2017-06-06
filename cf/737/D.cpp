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
#define smax(x, y) ((x) = fastmax((x), (y)))
#define smin(x, y) ((x) = fastmin((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 4000 + 10;
int dp[2][maxn][maxn],
	pd[2][maxn][maxn],
	a[maxn],
	sum[maxn],
	n;

int fastmax(int x, int y){
	return (((x-y)>>31)&(x^y))^x;
}

int fastmin(int x, int y){
	return (((x-y)>>31)&(x^y))^y;
}

#define get(x, y) (sum[y] - sum[x])

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		sum[i + 1] = sum[i] + a[i];
	}
	int cur = 0, pre = 1;
	for(short int k = 30; k >= 1; k--){
		cur^=pre^=cur^=pre;
		for(short int len = k; len <= n; ++len){
			for(short int i = 0; i + len <= n; ++i){
				short int j = i + len;
				dp[cur][i][j] = get(i, i + k) + pd[cur][i + k][j];
				pd[cur][i][j] = -get(j - k, j) + dp[cur][i][j - k];
				if(len^k){
					smax(dp[cur][i][j], get(i, i + k + 1) + pd[pre][i + k + 1][j]);
					smin(pd[cur][i][j], -get(j - k - 1, j) + dp[pre][i][j - k - 1]); 
				}
			}
		}
	}
	printf("%d", dp[cur][0][n]);
	return 0;
}
