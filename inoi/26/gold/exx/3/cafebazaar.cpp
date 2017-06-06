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
#define gotohell {cout << -1 << '\n'; return(0);}
#define cos cost

const int maxn = 2e2 + 10,
	  maxe = 4e4 + 100;
const LL Mab = 2e10;
LL cos[maxe],
   dis[maxn];
int par[maxn],
	too[maxe],
	cap[maxe],
	prv[maxe],
	hed[maxn],
	e, sou, syn;
bool neces[maxn],
	 inq[maxn];
queue<int> q;
vector<pll> adj[maxn];

void adde(int u, int v, LL cos = 0, int uv = 1, int vu = 0){
	too[e] = v, cap[e] = uv, ::cos[e] = +cos, prv[e] = hed[u], hed[u] = e++;
	too[e] = u, cap[e] = vu, ::cos[e] = -cos, prv[e] = hed[v], hed[v] = e++;
}

void spfa(void){
	memset(dis, +63, sizeof dis);
	memset(par, -1, sizeof par);
	memset(inq, 0, sizeof inq);
	dis[sou] = 0;
	q.push(sou);
	inq[sou] = true;
	while(sz(q)){
		int u = q.front();
		inq[u] = false;
		q.pop();
		for(int e = hed[u]; ~e; e = prv[e]){
			int v = too[e];
			LL w = cos[e];
			if(!cap[e] or dis[u] + w >= dis[v]) continue;
			dis[v] = dis[u] + w;
			par[v] = e^1;
			if(!inq[v]){
				inq[v] = true;
				q.push(v);
			}
		}
	}
	return;
}

void decrea(int u){
	while(~par[u]){
		int e = par[u];
		cap[e^0]++;
		cap[e^1]--;
		u = too[e];
	}
	return;
}

LL get(int n, int m){
	LL ret = 0;
	for(int i = n + m; i*2 < e; i++)
		if(!cap[i<<1])
			ret -= cos[i<<1];
	return ret;
}

int solve(int n, int m){
	if(!(n+m)) exit(0);
	memset(hed, -1, sizeof hed);
	memset(neces, 0, sizeof neces);
	e = 0;
	sou = n + m;
	syn = sou + 1;
	for(int i = 0; i < 2; i++){
		int tmp;
		cin >> tmp;
		while(tmp--){
			int x;
			cin >> x, x--;
			neces[n*i + x] = true;
		}
	}
	for(int i = 0; i < n; i++){
		adj[i].clear();
		adde(sou, i, (!neces[i]) * Mab);
	}
	for(int i = n; i < n + m; i++)
		adde(i, syn, (!neces[i]) * Mab);
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		while(tmp--){
			int fi, se;
			cin >> fi >> se;
			fi--;
			adde(i, fi + n, -se);
		}
	}
	LL ans = 0;
	while(true){
		spfa();
		if(!~par[syn])
			break;
		decrea(syn);
		bool can = true;
		for(int i = 0; i < n + m; i++)
			if(neces[i] and cap[i<<1])
				can = false;
		if(can)
			smax(ans, get(n, m));
	}
	for(int i = 0; i < n + m; i++)
		if(neces[i] and cap[i<<1])
			gotohell;
	cout << ans << '\n';
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	while(cin >> x >> y)
		solve(x, y);
	return 0;
}
