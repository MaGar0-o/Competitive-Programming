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

	registerValidation(argc, argv);

	int n = inf.readInt(2, 10, "n");
	inf.readSpace();
	int m = inf.readInt(2, 10, "m");
	inf.readSpace();
	int T = inf.readInt(1, 500, "T");
	inf.readEoln();

	inf.readInt(1, n, "sr");
	inf.readSpace();
	inf.readInt(1, m, "sc");
	inf.readEoln();
	
	int p = inf.readInt(1, 500, "p");
	inf.readEoln();
	for (int i = 0; i < p; i++){
		inf.readInt(1, n, "x[" + to_string(i+1) + "]");
		inf.readSpace();
		inf.readInt(1, m, "y[" + to_string(i+1) + "]");
		inf.readEoln();
	}

	int q = inf.readInt(0, T, "q");
	inf.readEoln();
	int prv = 0;
	for (int i = 0; i < q; i++) {
		inf.readToken("R|L", "dir[" + to_string(i + 1) + "]");
		inf.readSpace();
		prv = inf.readInt(prv + 1, T, "time[" + to_string(i+1) + "]");
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}
