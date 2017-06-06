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

int main()
{
	int n;
	cin >> n;
	LL ans = 0, sum = 0;
	for(int i = 0; i< n; i++){
		LL a;
		cin >> a;
		sum += a;
		smax(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
