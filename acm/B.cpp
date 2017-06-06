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
	int n, m;
	while(cin >> m >> n and (m or n)){
		n++;
		int a[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		int ans = 0;
		for(int i = 1; i < n; i++){
			bool can = true;
			for(int j = 0; j < m; j++)
				if(a[i][j] > a[0][j])
					can = false;
			ans += can;
		}
		cout << ans << '\n';
	}
	return 0;
}
