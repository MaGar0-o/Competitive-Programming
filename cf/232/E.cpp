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

const int maxn = 500 + 5,
	  maxq = 6e5 + 85 - 69;
bool can[maxn][maxn],
	 ans[maxq];
char s[maxn][maxn];
int n, m, qu;
vector<pair<int, pii> > vec[maxn][maxn];

void fuck(int i, int j){
	can[i][j] = false;
	if(i < n and can[i + 1][j] and !can[i + 1][j - 1])
		fuck(i + 1, j);
	if(j < n and can[i][j + 1] and !can[i - 1][j + 1])
		fuck(i, j + 1);
	return;
}

void dfs(int x, int y){
	if(s[x][y] == '#' or can[x][y]) return;
	can[x][y] = true;
	if(x < n)
		dfs(x + 1, y);
	if(y < n)
		dfs(x, y+1);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	scanf("%d", &qu);
	for(int i = 0; i < qu; i++){
		int fi, se, th, fo;
		scanf("%d%d%d%d", &fi, &se, &th, &fo);
		vec[fi][se].PB(MP(i, MP(th, fo)));
	}
	for(int i = n; i; --i){
		for(int j = i; j <= n; ++j)
			memset(can[j], false, sizeof can[j]);
		for(int j = m; j; --j){
			if(s[i][j] == '#') fuck(i, j);
			else dfs(i, j);
			for(auto quer : vec[i][j])
				ans[quer.L] = can[quer.R.L][quer.R.R];
		}
	}
	for(int i = 0; i < qu; i++)
		printf(ans[i] ? "Yes\n" : "No\n");
	return 0;
}
