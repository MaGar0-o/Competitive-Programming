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

set<vector<int>> st;
const int Mod = 10859;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int mask = 0; mask < (1 << 16); mask++){
		vector<int> vec(8);
		for(int r = 0; r < 4; r++)
			for(int c = 0; c < 4; c++){
				int id = r * 4 + c;
				int val = (mask >> id) & 1;
				if(val) vec[r]++, vec[4+c]++;
			}
		st.insert(vec);
	}
	LL val = sz(st) % Mod;
	cout << sz(st) << endl;
	return 0;
}
