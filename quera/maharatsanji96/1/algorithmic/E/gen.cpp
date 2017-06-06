//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
//#include "/home/magar/.testlib/testlib.h"
#include "/home/magar/.testlib/testlib.h"

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

const int maxn = 15;
int a[maxn];
int ord[maxn];
set<pii> s[3];

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	registerGen(argc, argv, 1);
	int n = rnd.next(2, 15),
		m = rnd.next(1, min(15, n * (n - 1) / 2)),
		f = rnd.next(1, min(15, n * (n - 1) / 2)),
		h = rnd.next(1, min(15, n * (n - 1) / 2));
	iota(ord, ord + n, 1);
	shuffle(ord, ord + n);
	int tmp = rnd.next(-2, +2);
	for (int i = 0; i < n; i++)
		a[i] = rnd.wnext(1, 15, tmp);
	for (int i = 0; sz(s[0]) < m; i++) {
		int fi = rnd.next(n);
		int se = (fi + rnd.next(1, n - 1)) % n;
		if (fi > se) swap(fi, se);
		s[0].insert(MP(fi, se));
	}
	for (int i = 0; sz(s[1]) < f; i++) {
		int fi = rnd.next(n);
		int se = (fi + rnd.next(1, n - 1)) % n;
		if (fi > se) swap(fi, se);
		s[1].insert(MP(fi, se));
	}
	for (int i = 0; sz(s[2]) < h; i++) {
		int fi = rnd.next(n);
		int se = (fi + rnd.next(1, n - 1)) % n;
		if (fi > se) swap(fi, se);
		s[2].insert(MP(fi, se));
	}
	cout << n << ' ' << m << ' ' << f << ' ' << h << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " \n"[i == n - 1];
	for (int i = 0; i < 3; i++)
		for (auto x : s[i])
			cout << ord[x.L] << ' ' << ord[x.R] << endl;
	return 0;
}
