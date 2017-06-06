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

const int maxn = 3000 + 85 - 69;
int a[maxn], h[maxn][maxn];
int val[maxn];
vector<int> adj[maxn];
int n;
queue<pii> q;
bool mark[maxn][maxn];
LL sum = 0;

int main(){
	memset(h, 63, sizeof h);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		sum += a[i];
		val[i] = !a[i];
		int nc;
		scanf("%d", &nc);
		for(int j = 0; j < nc; j++){
			int x;
			scanf("%d", &x);
			x--;
			adj[i].PB(x);
		}
	}
	int st, en;
	scanf("%d%d", &st, &en);
	st--, en--;
	h[st][val[st]] = 1;
	mark[st][val[st]] = true;
	q.push(MP(st, val[st]));
	while(sz(q)){
		pii v = q.front();
		q.pop();
		for(auto u : adj[v.L]){
			if(!mark[u][v.R + val[u]]){
				h[u][v.R + val[u]] = h[v.L][v.R] + 1;
				mark[u][v.R + val[u]] = true;
				q.push(MP(u, v.R + val[u]));
			}
		}
	}
	for(int i = 0; i <= n; i++)
		if(h[en][i] <= sum){
			printf("%d", i);
			return 0;
		}
	printf("No Solution");
	return 0;
}
