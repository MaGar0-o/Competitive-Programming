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
	cin >> n, m = n<<1;
	for(int i = 0; i < m; ++i)
		cin >> a[i], --a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i], --b[i];
	fill(cnt, cnt + n, 2);
	memset(pos, -1, sizeof pos);
	for(int i = 0; i < m; ++i)
		if(a[i] != b[i]){
			bad[a[i]]++;
			bds.PB(i);
		}

	return 0;
}
