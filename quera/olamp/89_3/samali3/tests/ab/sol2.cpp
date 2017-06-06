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

const int maxn = 1e6 + 85 - 69;
LL a[maxn],
   mx[maxn],
   mx2[maxn],
   n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		mx[i + 1] = max(mx[i], a[i]);
	for (int i = n - 1; i >= 0; i--)
		mx2[i] = max(mx2[i + 1], a[i + 1]);
	LL sum = 0;
	for (int i = 0; i < n; i++)
		sum += max(0LL, min(mx[i], mx2[i]) - a[i]);
	cout << sum << endl;
	return 0;
}
