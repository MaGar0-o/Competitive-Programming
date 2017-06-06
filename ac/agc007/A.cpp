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

const int maxn = 100;
string s[100];
bool mark[maxn][maxn];
int n, m;

void dfs(int i, int j){
	if(i >= n or j >= m or s[i][j] == '.') return;
	mark[i][j] = true;
	dfs(i + 1, j);
	dfs(i, j + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	dfs(0, 0);
	if(!mark[n - 1][m - 1]){
		cout << "Impossible\n";
		return 0;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
		cnt += count(all(s[i]), '#');
	if(cnt != n + m - 1)
		cout << "Impossible\n";
	else
		cout << "Possible\n";
	return 0;
}
