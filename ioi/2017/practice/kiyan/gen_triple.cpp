//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
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

#define HEAD "1"
#define TAIL "0"

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	if (argc < 2 or string(argv[1]) == "-h") {
		cerr << "usage: " << argv[0] << " \\\n\tnumber_of_test_cases \\\n\tsome_values_to_seed_random_function" << endl;
		return 0;
	}

	registerGen(argc, argv, 1);

	int t = atoi(argv[1]);
	cout << t << endl;
	for (int _ = 0; _ < t; _++) {
		int n = 8;
		int w = rnd.next(-2, +2);
		for (int i = 0; i < n; i++, cout << endl)
			for (int j = 0; j < n; j++)
				cout << (rnd.wnext(2, w) ? HEAD : TAIL);
		int r = rnd.next(1, 1),
			c = rnd.next(1, 3);
		cout << r << ' ' << c << endl;
	}
	return 0;
}
