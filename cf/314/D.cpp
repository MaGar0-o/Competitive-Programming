//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
	int n;
	cin >> n;
	LD mn = +1e18;
	LD mx = -1e18;
	for(int i = 0; i < n; i++){
		LD x, y;
		cin >> x >> y;
		y -= x;
		smax(mx, y);
		smin(mn, y);
	}
	cout << fixed << setprecision(10) << (mx - mn / 2) << endl;
	return 0;
}
