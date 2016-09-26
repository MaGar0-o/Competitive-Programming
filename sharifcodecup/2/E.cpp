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

const int maxn = 1e5 + 85 - 69;
vector<LD> po;
vector<pll> vec;
pll a[maxn];
int n, m;

LD placeof(pll l1, pll l2){
	return LD(l1.R - l2.R) / LD(l2.L - l1.L);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vec.reserve(maxn);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i].R >> a[i].L;
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		if(sz(vec) >= 1 and vec.back().L == a[i].L)
			vec.pop_back();
		while(sz(vec) >= 2 and placeof(vec.back(), a[i]) <= placeof(vec.back(), vec[sz(vec) - 2]))
			vec.pop_back();
		vec.PB(a[i]);
	}
	for(int i = 0; i + 1 < sz(vec); i++)
		po.PB(placeof(vec[i], vec[i + 1]));
	for(int i = 0; i < m; i++){
		LL ti;
		cin >> ti;
		int id = lower_bound(all(po), LD(ti)) - po.begin();
		cout << vec[id].L * ti + vec[id].R << ' ';
	}
	cout << endl;
	return 0;
}
