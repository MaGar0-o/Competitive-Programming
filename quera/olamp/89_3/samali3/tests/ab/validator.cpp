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

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	registerValidation(argc, argv);
	int n = inf.readInt(1, 1000000, "n");
	inf.readEoln();
	for (int i = 0; i < n; i++) {
		int x = inf.readInt(0, 1000, format("a[%d]", n));
		if (i + 1 < n)
			inf.readSpace();
	}
	inf.readEoln();
	inf.readEof();
	return 0;
}
