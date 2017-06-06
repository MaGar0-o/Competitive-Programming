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

#define NO return cout << "no\n", 0;
#define YES return cout << "yes\n", 0;

int solve(void) {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n & 1 ^ 1)
		NO;
	for (int i = 0; i < n / 2; i++)
		if (a[i] != i + 1 or a[n - i - 1] != i + 1)
			NO;
	if (a[n / 2] != (n+1) / 2)
		NO;
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
