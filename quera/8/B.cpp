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
	int n;
	cin >> n;
	int a = 5,
		b = 0,
		c = 0;
	while(n--){
		int val;
		cin >> val;
		if(val == 2)
			c--, b++;
		else
			b++;
	}
	cout << a << ' ' << b << ' ' << c << '\n';
	return 0;
}
