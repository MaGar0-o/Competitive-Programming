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

const int maxn = 1e5 + 85 - 69;
int mark[maxn],
	p[maxn],
	pos[maxn],
	com[maxn],
	cyccnt[maxn],
	n, m, q, compcnt;
bool oskol[maxn];
vector<int> vec[maxn];

void dfs(int v){
	mark[v] = 1;
	pos[v] = sz(vec[compcnt]);
	com[v] = compcnt;
	vec[compcnt].PB(v);
	if(p[v] == m){
		oskol[v] = true;
		cyccnt[v] = 1;
		goto bokhor;
	}
	if(mark[p[v]] == 1)
		goto bokhor;
	if(!mark[p[v]])
		dfs(p[v]);
	if(oskol[p[v]]){
		oskol[v] = true;
		cyccnt[v] = cyccnt[p[v]] + 1;
		goto bokhor;
	}
bokhor:
	mark[v] = 2;
	return;
}

int findans(int v){
	if(v >= n - m){
		int id = v - (n - m);
		if(oskol[id]){
			if(n - m + 1 >= sz(vec[com[id]]) - pos[id])
				return n - cyccnt[id];
			return vec[com[id]][pos[id] + n - m + 1] - 1;
		}
		int tmp = (pos[id] + n - m + 1) % sz(vec[com[id]]);
		return vec[com[id]][tmp] - 1;
	}
	int tmp = n;
	n = v + m;
	int ret = findans(v);
	n = tmp;
	return ret;
}

int main(){
	ifstream cin("shufflegold.in");
	ofstream cout("shufflegold.out");
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x, x--;
		p[x] = i + 1;
	}
	for(int i = 0; i < m; i++)
		if(!mark[i]){
			dfs(i);
			compcnt++;
		}
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		x = n - x;
		cout << findans(x) + 1 << '\n';
	}
	return 0;
}
