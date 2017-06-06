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

#define	YES	return cout << "Valid\n", 0
#define	NO	return cout << "Invalid\n", 0

int solve(void) {
	int n;
	cin >> n;
	char s[n];
	cin >> s;
	char prv = '.';
	for (int i = 0; i < n; i++) {
		if (s[i] != '.') {
			if (prv == '.') {
				if (s[i] == 'T')
					NO;
				prv = s[i];
			}
			else if (prv == s[i])
				NO;
			else
				prv = '.';
		}
	}
	if (prv ^ '.')
		NO;
	else
		YES;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
