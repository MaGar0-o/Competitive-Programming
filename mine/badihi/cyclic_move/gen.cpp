//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
#include "../../../testlib/testlib.h"

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

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	registerGen(argc, argv, 1);
	int cnt = atoi(argv[1]) * 2;
	int n = rnd.next(1, 1000000000 / (1 << cnt)) * (1 << cnt);
	cout << n << endl;
	return 0;
}
