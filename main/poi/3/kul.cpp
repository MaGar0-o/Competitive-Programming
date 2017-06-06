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
#define cos COST

const int maxn = 1000 + 10;
int too[maxn * 8],
	cap[maxn * 8],
	prv[maxn * 8],
	cos[maxn * 8],
	hed[maxn],
	dis[maxn],
	par[maxn],
	a[maxn],
	n, edg, sou, syn;
bool inq[maxn];
queue<int> q;

void add_edge(int u, int v, int uv, int cos = 0){
	too[edg] = v, cap[edg] = uv, prv[edg] = hed[u], ::cos[edg] = cos, hed[u] = edg++;
	too[edg] = u, cap[edg] = 0, prv[edg] = hed[v], ::cos[edg] = -cos, hed[v] = edg++;
}

int spfa(void){
	memset(dis, 63, sizeof dis);
	q.push(sou);
	inq[sou] = true;
	dis[sou] = 0;
	while(sz(q)){
		int u = q.front();
		q.pop();
		//cout << u << endl;
		inq[u] = false;
		for(int e = hed[u]; ~e; e = prv[e]) if(cap[e]){
			//cout << '\t' << e << endl;
			int v = too[e];
			//cout << "#" << dis[u] << ' ' << cos[e] << ' ' << v << dis[v] << endl;
			if(dis[u] + cos[e] < dis[v]){
				//cout << "HI" << endl;
				dis[v] = dis[u] + cos[e];
				par[v] = e^1;
				if(!inq[v]){
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	int u = syn;
	while(u != sou){
		cap[par[u]]++;
		cap[par[u]^1]--;
		u = too[par[u]];
	}
	return dis[syn];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(hed, -1, sizeof hed);
	cin >> n;
	sou = n + 0;
	syn = n + 1;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i]) add_edge(sou, i, a[i] - 1), sum += a[i] - 1;
		else add_edge(i, syn, 1);
	}
	for(int i = 0; i < n; i++){
		add_edge(i, (i + 1) % n, 1e5, 1);
		add_edge(i, (i + n - 1) % n, 1e5, 1);
	}
	int ans = 0;
	while(sum--)
		ans += spfa();
	cout << ans << endl;
	return 0;
}
