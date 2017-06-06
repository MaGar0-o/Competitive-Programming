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

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	registerGen(argc, argv, 1);
	int n = rnd.wnext(50, 500, 2);
	int pc = rnd.wnext(0, n, -1);
	int arr[n];
	fill(arr, arr + pc, 1);
	fill(arr + pc, arr + n, 0);
	shuffle(arr, arr + n);
	int k = rnd.next(0, n - pc);
	cout << n << ' ' << k << '\n';
	for(int i = 0; i < n; i++)
		cout << (arr[i] ? 'K' : 'B');
	return 0;
}
