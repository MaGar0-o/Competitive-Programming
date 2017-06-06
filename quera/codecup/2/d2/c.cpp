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

const int maxn = 1e6;
vector<int> vec[maxn][2],
	com[maxn],
	ans;
queue<int> q;
int has[maxn];
bool mark[maxn];
int n, m, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x, x--;
		q.push(x);
		mark[x] = true;
	}
	for(int i = 0; i < k; i++){
		int p, q;
		cin >> p >> q;
		for(int j = 0; j < p; j++){
			int x;
			cin >> x, x--;
			vec[i][0].PB(x);
			com[x].PB(i);
		}
		for(int j = 0; j < q; j++){
			int x;
			cin >> x, x--;
			vec[i][1].PB(x);
		}
	}
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(auto id : com[u]){
			has[id]++;
			if(has[id] == sz(vec[id][0]))
				for(auto v : vec[id][1])
					if(!mark[v])
						q.push(v), mark[v] = true;
		}
	}
	for(int i = 0; i < n; i++)
		if(mark[i])
			ans.PB(i+1);
	cout << sz(ans) << '\n';
	for(auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}
