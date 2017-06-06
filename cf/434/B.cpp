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

const int maxn = 1000 + 85 - 69;
int a[maxn][maxn],
	up[maxn][maxn],
	dn[maxn][maxn],
	le[maxn][maxn],
	ri[maxn][maxn],
	n, m, q;

int getup(int fi, int se){
	int ret = 0;
	int p1 = se,
		p2 = se;
	for(int i = up[fi][se]; i > 0; i--){
		while(p1 >= 0 and up[fi][p1] >= i) p1--;
		while(p2 < m and up[fi][p2] >= i) p2++;
		smax(ret, i * (p2 - p1 - 1));
	}
	return ret;
}

int getdn(int fi, int se){
	int ret = 0;
	int p1 = se,
		p2 = se;
	for(int i = dn[fi][se]; i > 0; i--){
		while(p1 >= 0 and dn[fi][p1] >= i) p1--;
		while(p2 < m and dn[fi][p2] >= i) p2++;
		smax(ret, i * (p2 - p1 - 1));
	}
	return ret;
}

int getle(int fi, int se){
	int ret = 0;
	int p1 = se,
		p2 = se;
	for(int i = le[fi][se]; i > 0; i--){
		while(p1 >= 0 and le[p1][se] >= i) p1--;
		while(p2 < n and le[p2][se] >= i) p2++;
		smax(ret, i * (p2 - p1 - 1));
	}
	return ret;
}

int getri(int fi, int se){
	int ret = 0;
	int p1 = se,
		p2 = se;
	for(int i = ri[fi][se]; i > 0; i--){
		while(p1 >= 0 and ri[p1][se] >= i) p1--;
		while(p2 < n and ri[p2][se] >= i) p2++;
		smax(ret, i * (p2 - p1 - 1));
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++){
		le[i][0] = a[i][0];
		for(int j = 1; j < m; j++)
			le[i][j] = a[i][j] * (1+le[i][j - 1]);
		ri[i][m - 1] = a[i][m - 1];
		for(int j = m - 2; j >= 0; j--)
			ri[i][j] = a[i][j] * (1+ri[i][j + 1]);
	}
	for(int j = 0; j < m; j++){
		up[0][j] = a[0][j];
		for(int i = 1; i < n; i++)
			up[i][j] = a[i][j] * (1+up[i - 1][j]);
		dn[n - 1][j] = a[n - 1][j];
		for(int i = n - 2; i >= 0; i--)
			dn[i][j] = a[i][j] * (1+dn[i + 1][j]);
	}
	while(q--){
		int ty, fi, se;
		cin >> ty >> fi >> se;
		fi--, se--;
		if(ty == 1){
			a[fi][se] = 1 - a[fi][se];
			up[0][se] = a[0][se];
			dn[n - 1][se] = a[n - 1][se];
			le[fi][0] = a[fi][0];
			ri[fi][m - 1] = a[fi][m - 1];
			for(int i = 1; i < n; i++)
				up[i][se] = a[i][se] * (1+up[i - 1][se]);
			for(int i = n - 2; i >= 0; i--)
				dn[i][se] = a[i][se] * (1+dn[i + 1][se]);
			for(int j = 1; j < m; j++)
				le[fi][j] = a[fi][j] * (1+le[fi][j - 1]);
			for(int j = m - 2; j >= 0; j--)
				ri[fi][j] = a[fi][j] * (1+ri[fi][j + 1]);
		}
		else
			cout << max(max(getup(fi, se), getdn(fi, se)),
					max(getle(fi, se), getri(fi, se))) << '\n';
	}
	return 0;
}
