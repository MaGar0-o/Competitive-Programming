//sobskdrbhvk
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
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		if(((i % 3 == 0 or i % 7 == 0) and x != 0) or ((i % 3 != 0 and i % 7 != 0) and x != i))
			cout << (i - 1) % n + 1 << '\n';
	}
	return 0;
}
