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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	cout << t << endl;
	while (t--) {
		int n;
		cin >> n;
		cout << n << endl;
		for (int i = 0; i < 2*n; i++)
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;
				cout << x << " \n"[j == n - 1];
			}
	}
	return 0;
}
