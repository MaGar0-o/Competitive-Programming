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
#define int short int

int pos[1000][200];
int indeg[1000];
bool adj[1000][1000];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	while(cin >> n >> k and (n or k)){
		for(int i = 0; i < k; i++)
			for(int j = 0; j < n; j++){
				int x;
				cin >> x, x--;
				pos[x][i] = j;
			}
		for(int i = 0; i < n; i++)
			memset(adj[i], false, n);
		memset(indeg, 0, n<<1);
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++){
				int cnt = 0;
				for(int kk = 0; kk < k; kk++)
					cnt += pos[i][kk] < pos[j][kk];
				if(cnt > k / 2)
					adj[i][j] = true, indeg[j]++;
				else if(k - cnt > k / 2)
					adj[j][i] = true, indeg[i]++;
			}
		bool mark[n];
		memset(mark, false, n);
		bool bad = false;
		int ans[n];
		for(int i = 0; i < n; i++){
			int u = -1;
			for(int j = 0; j < n; j++)
				if(!mark[j] and indeg[j] == 0){
					u = j;
					break;
				}
			if(u == -1){
				bad = true;
				break;
			}
			mark[u] = true;
			ans[i] = u + 1;
			for(int j = 0; j < n; j++)
				if(adj[u][j])
					indeg[j]--;
		}
		if(bad)
			cout << "No solution\n";
		else
			for(int i = 0; i < n; i++)
				cout << ans[i] << "\n "[i != n - 1];
	}
	return 0;
}
