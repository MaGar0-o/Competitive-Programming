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
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		int k = x / 3;
		if(x % 3 == 0)
			vec[0].PB(k), vec[1].PB(2 * k);
		else if(x % 3 == 1)
			vec[0].PB(2 * k), vec[1].PB(k + 1);
		else
			vec[0].PB(2 * k + 1), vec[1].PB(
	}
	return 0;
}
