//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

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

#define HEAD '1'
#define TAIL '0'

const int maxn = 8;
const int maxlen = 1 << maxn;
string row[maxlen];
int n, x, y;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int len = 1 << n;
	int ret = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++) {
			char x;
			cin >> x;
			if (x == HEAD)
				ret ^= i * len + j;
			row[i] += x;
		}
	cin >> x >> y;
	x--, y--;
	ret ^= x * len + y;
	x = ret / len;
	y = ret % len;
	row[x][y] ^= HEAD ^ TAIL;
	cout << n << endl;
	for (int i = 0; i < len; i++)
		cout << row[i] << '\n';
	return 0;
}
