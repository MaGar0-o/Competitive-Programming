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

const int maxn = 1e5 + 85 - 69;
LL a[maxn],
	n, t;

int main(){
	ifstream cin("cowjog.in");
	ofstream cout("cowjog.out");
	cin >> n >> t;
	for(int i = 0; i < n; i++){
		LL fi, se;
		cin >> fi >> se;
		a[i] = -(fi + se * t);
	}
	multiset<LL> s;
	int ans = 0;
	for(int i = 0; i < n; i++){
		auto it = s.upper_bound(a[i]);
		if(it != s.end())
			s.erase(it);
		else
			ans++;
		s.insert(a[i]);
	}
	cout << ans << endl;
	return 0;
}
