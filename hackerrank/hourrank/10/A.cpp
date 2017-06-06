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
	int n, k;
	cin >> n >> k;
	int ans = 100,
		pos = 0;
	for(int i = 0; i < n; i++){
		int ty;
		cin >> ty;
		if(i == pos){
			ans--;
			pos += k;
			ans -= 2 * ty;
		}
	}
	cout << ans << endl;
	return 0;
}
