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

const int maxn = 100 + 85 - 69;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if(count(a, a + n, a[n - 1]) == 1 or a[0] < (a[n - 1] + 1) / 2){
hell:
		cout << "impossible\n";
		return 0;
	}
	for(int i = 1; i <= a[n - 1]; i++){
		int id = lower_bound(a, a + n, i) - a;
		if(i * 2 == 
	}
	cout << "Possible" << endl;
	return 0;
}
