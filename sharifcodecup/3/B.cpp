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

void mul(vector<int> &vec, int x){
	for(int i = 0; i < sz(vec); i++)
		vec[i] *= x;
	for(int i = 0; i + 1 < sz(vec); i++){
		vec[i + 1] += vec[i] / 10;
		vec[i] %= 10;
	}
	while(vec.back() >= 10){
		vec.PB(vec.back() / 10);
		vec[sz(vec) - 2] %= 10;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, d;
	cin >> n >> d;
	vector<int> a;
	a.PB(1);
	for(int i = 1; i <= n; i++)
		mul(a, i);
	int ans = 0;
	for(auto x : a)
		ans += x == d;
	cout << ans << endl;
	return 0;
}
