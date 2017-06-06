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

const int maxn = 1e6 + 10;
int adj[maxn][2];
bool mark[maxn];
int sz = 1;

void add(int num){
	int u = 0;
	for(int i = 30; i >= 0; i--){
		int c = (num>>i)&1;
		int &v = adj[u][c];
		if(v == -1) v = sz++;
		u = v;
	}
	mark[u] = true;
	return;
}

bool we_have(int num){
	int u = 0;
	for(int i = 30; i >= 0; i--){
		int c = (num>>i)&1;
		int &v = adj[u][c];
		if(v == -1) return false;
		u = v;
	}
	return mark[u];
}
