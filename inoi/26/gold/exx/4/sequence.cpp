//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 1e5 + 85,
	  maxk = 210;
LL dp[2][maxn];
int par[maxk][maxn],
	stc[maxn],
	sz;
LL sum[maxn],
   a[maxn];
int n, k;

LD inters(int id, int l1, int l2){
	LD a1 = sum[l1],
	   a2 = sum[l2];
	LD b1 = dp[id][l1] - sum[l1] * sum[l1],
	   b2 = dp[id][l2] - sum[l2] * sum[l2];
	return (b2 - b1) / (a1 - a2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum[i] = a[i];
		if(i) sum[i] += sum[i - 1];
	}
	int cur = 0, pre = 1;
	//dp[i] = (dp[j] - sum[j] * sum[j]) + sum[j] * sum[i];
	for(int i = 1; i <= k; i++){
		swap(cur, pre);
		memset(dp[cur], -63, sizeof dp[cur]);
		stc[(sz = 0)++] = i - 1;
		int ptr = 0;
		for(int j = i; j < n; j++){
			while(ptr + 1 < sz and sum[j] > inters(pre, stc[ptr], stc[ptr + 1]))
				ptr++;
			int id = stc[ptr];
			dp[cur][j] = dp[pre][id] + sum[id] * (sum[j] - sum[id]);
			par[i][j] = stc[ptr];
			while(sz >= 1 and sum[stc[sz - 1]] == sum[j] and dp[pre][j] - sum[j] * sum[j] > dp[pre][stc[sz - 1]] - sum[stc[sz - 1]] * sum[stc[sz - 1]])
				sz--;
			if(sz >= 1 and sum[stc[sz - 1]] == sum[j]) continue;
			while(sz >= 2 and inters(pre, stc[sz - 1], j) < inters(pre, stc[sz - 1], stc[sz - 2]))
				sz--;
			stc[sz++] = j;
			smin(ptr, sz - 1);
		}
	}
	int col = n - 1;
	cout << dp[cur][col] << '\n';
	for(int i = k; i; i--)
		cout << (col = par[i][col]) + 1 << ' ';
	cout << '\n';
	return 0;
}
