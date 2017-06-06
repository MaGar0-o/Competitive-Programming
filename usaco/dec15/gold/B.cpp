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

int t, a, b, ans;
bool mark[2][5000000 + 1];

void dfs(int x, bool ty = 0){
	if(x > t or mark[ty][x])
		return;
	mark[ty][x] = true;
	smax(ans, x);
	dfs(x + a, ty);
	dfs(x + b, ty);
	if(!ty)
		dfs(x / 2, !ty);
	return;
}

int main(){
	ifstream cin("feast.in");
	ofstream cout("feast.out");
	cin >> t >> a >> b;
	dfs(0);
	cout << ans << endl;
	return 0;
}
