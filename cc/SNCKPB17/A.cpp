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

void solve(void) {
	string s;
	cin >> s;
	bool adj = false;
	int dif = 0;
	for (int i = 0; i < sz(s); i++) {
		char c = s[i];
		if (c == 's') {
			if (adj)
				adj = false;
			else if (i + 1 < sz(s) and s[i + 1] == 'm')
				dif++, i++;
			else
				dif--;
		}
		else
			adj = true, dif++;
	}
	cout << (dif ? dif < 0 ? "snakes" : "mongooses" : "tie") << endl;
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
