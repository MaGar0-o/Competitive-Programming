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

const int maxn = 1e5 + 10;
int n, m;
int a[maxn],
	b[maxn];

bool bad(int x, int y, int l, int r){
	if (x == l) return false;

	if (x > l)
		swap(x, l), swap(y, r);

	return y >= l and y < r;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
		}
		cin >> m;
		for (int i = 0; i < m; i++){
			cin >> a[i] >> b[i];
			for (int j = 0; j < i; j++)
				if (bad(a[i], b[i], a[j], b[j]))
					assert(0);
		}
	}
	return 0;
}
