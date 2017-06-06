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

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	registerGen(argc, argv, 1);

	int n = rnd.next(2, 10),
		m = rnd.next(2, 10),
		T = rnd.next(1, 500),
		p = rnd.next(1, 500);
	
	cout << n << ' ' << m << ' ' << T << endl
		<< rnd.next(1, n) << ' ' << rnd.next(1, m) << endl
		<< p << endl;

	for (int i = 0; i < p; i++)
		cout << rnd.next(1, n) << ' ' << rnd.next(1, m) << endl;

	vector<pair<char, int> > turns;
	int prob = rnd.wnext(1, 100, -2);
	for (int i = 1; i <= T; i++)
		if (not rnd.next(prob))
			turns.PB(MP((rnd.next(2) ? 'L' : 'R'), i));

	cout << sz(turns) << endl;
	for (auto quer : turns)
		cout << quer.L << ' ' << quer.R << endl;

	return 0;
}
