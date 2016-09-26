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

int n, m, k;
bool mark[1000][1000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		mark[fi][se] = true;
	}
	if(k & 1){
		cout << 0 << endl;
		return 0;
	}
	if(k == n * m){
		cout << -1 << endl;
		return 0;
	}
	cout << 1 << '\n';
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!mark[i][j]){
				cout << i + 1 << ' ' << j + 1 << '\n';
				return 0;
			}
	return 0;
}
