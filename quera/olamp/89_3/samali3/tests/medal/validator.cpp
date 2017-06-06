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

void read_scenario(void){
	int n = inf.readInt(1, 2000, "n");
	inf.readEoln();
	for (int i = 0; i < n; i++) {
		inf.readInt(0, 1000000000, format("s[%d]", i + 1));
		if (i < n - 1)
			inf.readSpace();
	}
	inf.readEoln();
	int m = inf.readInt(1, 2000, "m");
	inf.readEoln();
	for (int i = 0; i < m; i++) {
		int x, y;
		x = inf.readInt(1, n, format("a[%d]", i + 1));
		inf.readSpace();
		y = inf.readInt(x, n, format("b[%d]", i + 1));
		if (i < m - 1)
			inf.readSpace();
	}
	inf.readEoln();
}

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	registerValidation(argc, argv);
	int t = inf.readInt(1, 20, "t");
	inf.readEoln();
	for (int i = 0; i < t; i++)
		read_scenario();
	inf.readEof();

	return 0;
}
