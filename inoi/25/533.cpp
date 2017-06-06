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

const int maxn = 1e6 + 85 - 69;
LL a[maxn],
   b[maxn],
   n, m, sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	a[n] = 2e18 + 100;
	m -= sum;
	int lasti = -1;
	for(LL i = 0; i < n and m / (i + 1); i++){
		lasti = i;
		b[i] = min(a[i + 1] - a[i] - 1, m / (i + 1));
		m -= b[i] * (i + 1);
	}
	for(int i = n - 1; i >= 0; i--)
		b[i] += b[i + 1];
	if(m){
		while(a[lasti] + b[lasti] == a[lasti + 1] + b[lasti + 1] - 1)
			lasti++;
		while(m--)
			a[lasti--]++;
	}
	for(int i = 0; i < n; i++)
		cout << a[i] + b[i] << ' ';
	cout << '\n';
	return 0;
}
