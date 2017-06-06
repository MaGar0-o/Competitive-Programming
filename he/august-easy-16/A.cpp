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

int naugh[1000000];

int digof(int val){
	int ret = 0;
	while(val)
		val /= 10, ret++;
	return ret;
}

bool isnaugh(int val){
	int dig = digof(val);
	int ret = 0;
	for(int i = 2; i * i <= val; i++)
		if(val % i == 0){
			ret++;
			while(val % i == 0) val /= i;
		}
	return ret + (val > 1) == dig;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	naugh[1] = 1;
	for(int i = 2; i <= 100000; i++)
		naugh[i] = naugh[i - 1] + isnaugh(i);
	int q;
	cin >> q;
	while(q--){
		int fi, se;
		cin >> fi >> se;
		cout << naugh[se] - naugh[fi - 1] << '\n';
	}
	return 0;
}
