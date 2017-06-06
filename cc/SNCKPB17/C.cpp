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

int n;
char s[2][100000 + 100];

void solve(void) {
	cin >> n;
	for (int i = 0; i < n + n; i++)
		cin >> s[i / n][i % n];
	int orcnt = 0,
		f = 1;
	bool two_in_column = false;
	int prv = 0;
	for (int i = 0; i < n; i++) {
		if (s[0][i] == '*' or s[1][i] == '*') {
			orcnt++;
			if (s[0][i] == '*' and s[1][i] == '*') {
				two_in_column = true;
				if (prv)
					f++;
				prv = 3;
			}
			else if (s[0][i] == '*') {
				if (prv & 1)
					f++, prv = 1;
				else
					prv |= 1;
			}
			else {
				if (prv & 2)
					f++, prv = 2;
				else
					prv |= 2;
			}
		}
	}
	cout << (two_in_column ? min(orcnt, f) : max(0, min(orcnt - 1, f))) << endl;
}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		solve();
	return 0;
}
