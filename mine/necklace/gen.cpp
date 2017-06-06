//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
#include "../../testlib/testlib.h"

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

const int maxn = 1000 + 10;
vector<pii> edg;
vector<bool> vec;
int deg[maxn];

int main(int argc, char** argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	registerGen(argc, argv, 1);
	LL n = atoi(argv[1]);
	LL m = rnd.next(1LL, min(n * (n - 1) / 2, 900LL));
	for(int i = 0; i < n * (n - 1) / 2; i++)
		vec.PB(i < m);
	shuffle(all(vec));
	int sz = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			if(vec[sz++])
				deg[i]++, deg[j]++, edg.PB(rnd.next(2) ? MP(i, j) : MP(j, i));
	/*for(int i = 0; i < n; i++)
		if(deg[i] & 1)
			edg.PB(rnd.next(2) ? MP(i, (int)n) : MP((int)n, i));
	*/
	cout << n << ' ' << sz(edg) << '\n';
	for(int i = 0; i < sz(edg); i++)
		cout << edg[i].L+1 << ' ' << edg[i].R+1 << '\n';
	return 0;
}
