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

const int maxn = 110,
	  maxal = 26;
string s[maxn];
int d[maxn][maxn],
	dis[maxn][maxn],
	par[maxn][maxn];
int cnt[maxn][maxal];
int vec[maxn], vecsz = 0;
bool mark[maxn];
queue<int> q;
int n, l;
vector<int> adj[maxn];
string ans;

int dif(int x, int y){
	int ret = l;
	for(int i = 0; i < 26; i++)
		ret -= min(cnt[x][i], cnt[y][i]);
	return ret;
}

void makestr(int v, int u){
	vecsz = 0;
	do{
		vec[vecsz++] = u;
		u = par[v][u];
	}while(u != v);
	vec[vecsz++] = v;
	string str;
	for(int i = vecsz - 1; i >= 0; i--)
		str += s[vec[i]], str += ' ';
	if(ans == "") ans = str;
	else smin(ans, str);
	return;
}

void bfs(int st){
	memset(mark, false, sizeof mark);
	d[st][st] = 0;
	mark[st] = true;
	q.push(st);
	while(sz(q)){
		int v = q.front();
		q.pop();
		for(auto u : adj[v])
			if(!mark[u]){
				d[st][u] = d[st][v] + 1;
				par[st][u] = v;
				mark[u] = true;
				q.push(u);
			}
	}
	return;
}

bool cmp(int v, int u){
	return s[v] < s[u];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(d, 63, sizeof d);
	cin >> n >> l;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int j = 0; j < l; j++)
			cnt[i][s[i][j] - 'a']++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dis[i][j] = dif(i, j);
			if(dis[i][j] == 1)
				adj[i].PB(j);
		}
		sort(all(adj[i]), cmp);
	}
	for(int i = 0; i < n; i++)
		bfs(i);
	int Min = 100000;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(dis[i][j] == l)
				smin(Min, d[i][j]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(dis[i][j] == l and d[i][j] == Min)
				makestr(i, j);
	cout << ans << endl;
	return 0;
}
