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

const int maxn = 2e5 + 85 - 69;
set<pii> sa;
set<pair<pii, int>, greater<pair<pii, int> > > sb;
int a[maxn],
	b[maxn],
	ada[maxn],
	comat[maxn],
	n, m, ans, ans2;

int main(){
	memset(comat, -1, sizeof comat);
	scanf("%d %d", &n, &m);
	for(int i =0; i < n; i++){
		scanf("%d", a + i);
		sa.insert(MP(a[i], i));
	}
	for(int i = 0; i < m; i++){
		scanf("%d", b + i);
		sb.insert(MP(MP(b[i], -b[i]), i));
	}
	while(sz(sb)){
		auto x = *sb.begin();
		sb.erase(sb.begin());
		auto it = sa.lower_bound(MP(x.L.L, -1));
		if(it == sa.end() or it->L != x.L.L){
			if(x.L.L == 1) continue;
			x.L.L = (x.L.L + 1) >> 1;
			sb.insert(x);
		}
		else{
			sa.erase(it);
			comat[it->R] = x.R;
			ans++;
		}
	}
	for(int i = 0; i < n; i++){
		int id = comat[i];
		if(id == -1) continue;
		while(b[id] != a[i]){
			b[id] = (b[id] + 1) >> 1;
			ada[id]++;
			ans2++;
		}
	}
	printf("%d %d\n", ans, ans2);
	for(int i = 0; i < m; i++)
		printf("%d ", ada[i]);
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%d ", comat[i] + 1);
	printf("\n");
	return 0;
}
