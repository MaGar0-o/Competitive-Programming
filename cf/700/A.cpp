//sobskdrbhvk
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
	LD l, v1, v2, tim = 0;
	int n, k;
	cin >> n >> l >> v1 >> v2 >> k;
	while(n > 0){
		tim += l / v2;
		n -= k;
		l -= (l / v2) * v1;
	}
	cout << tim << endl;
	return 0;
}
