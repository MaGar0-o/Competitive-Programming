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

const int maxn = 2e4 + 85 - 69;
int a[maxn],
	b[maxn],
	p[maxn],
	n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 1; i <= n; i++){
		a[p[i]] = (n - p[i]) * 20010 + i;
		b[p[i]] = (p[i] - 1) * 20010 + i;
	}
	for(int i = 1; i <= n; i++)
		cout << b[i] << ' ';
	cout << '\n';
	for(int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';
	return 0;
}
