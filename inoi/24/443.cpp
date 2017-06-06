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

const int maxn = 5e4 + 85 - 69,
	  maxk = 101;
int vec[maxk][maxn],
	siz[maxk],
	dis[maxn],
	a[maxn],
	n, m, t, k, ans;
bool mark[maxn];
vector<pii> adj[maxn];

bool cmp(pii x, pii y){
	return x.R < y.R;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> t >> k;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB({se, th});
		adj[se].PB({fi, th});
	}
	for(int i = 0; i < n; i++)
		sort(all(adj[i]), cmp);
	for(int i = 0; i < t; i++)
		cin >> a[i], a[i]--;
	fill(dis, dis + n, k + 1);
	for(int i = 0; i < t; i++){
		dis[a[i]] = 0;
		vec[0][siz[0]++] = a[i];
		for(int i = 0; i < k; i++){
			while(siz[i]){
				int v = vec[i][--siz[i]];
				if(!mark[v]){
					mark[v] = true;
					//cout << "I found " << v+1 << ' ' << dis[v] << endl;
					ans++;
				}
				if(dis[v] < i) continue;
				for(auto e : adj[v]){
					if(i + e.R >= k) break;
					if(i + e.R < dis[e.L]){
						//cout << "relaxing " << v << ' ' << e.L << ' ' << e.R << endl;
						vec[i + e.R][siz[i + e.R]++] = e.L;
						dis[e.L] = i + e.R;
					}
				}
			}
		}
		cout << n - ans << '\n';
	}
	return 0;
}
