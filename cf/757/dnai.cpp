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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n
		>> s;
	n++;
	int ans = 0;
	for(int mask = 0; mask < (1 << n); mask++){
		vector<int> vec;
		int num = 0;
		for(int i = 0; i < sz(s); i++){
			if((mask>>i)&1)
				vec.PB(num), num = 0;
			num = num * 2 + s[i] - '0';
		}
		vec.PB(num);
		if((mask >> sz(s)) & 1)
			vec.PB(0);
		if(sz(vec) <= 2) continue;
		vec.erase(vec.begin());
		vec.erase(vec.end() - 1);
		sort(all(vec));
		vec.resize(unique(all(vec)) - vec.begin());
		if(vec.back() == sz(vec) and vec[0] != 0){
			ans++;
			for(int j = 0; j < n; j++)
				if((mask >> j)&1)
					cout << 1;
				else
					cout << 0;
			cout << '\n';
		}
	}
	cout << ans << endl;
	return 0;
}
