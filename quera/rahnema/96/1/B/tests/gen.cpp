//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
#include "testlib.h"

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

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	registerGen(argc, argv, 1);

	int w = rnd.next(-2, 2);
	int n = rnd.wnext(2, 200, w),
		m = rnd.wnext(2, 200, w);

	vector<pair<pii, pii>> vec;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			pair<pii, pii> seg = {{i, j}, {i + 1, j}};
			vec.PB(seg);
			seg = {{i, j}, {i, j + 1}};
			vec.PB(seg);
		}
	for (int i = 1; i < n; i++) {
		pair<pii, pii> seg = {{i, m}, {i + 1, m}};
		vec.PB(seg);
	}
	for (int j = 1; j < m; j++) {
		pair<pii, pii> seg = {{n, j}, {n, j + 1}};
		vec.PB(seg);
	}

	shuffle(all(vec));
	for (auto &seg : vec)
		if (rnd.next(2))
			swap(seg.L, seg.R);
	
	cout << n << ' ' << m << endl;
	for (auto seg : vec)
		cout << seg.L.L << ' ' << seg.L.R << ' '
			<< seg.R.L << ' ' << seg.R.R << endl;

	return 0;
} 
