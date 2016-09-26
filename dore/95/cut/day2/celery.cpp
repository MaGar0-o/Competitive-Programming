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
int don[maxn],
	n;
vector<pair<int, pii> > peo;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i){
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; ++j){
			int x;
			cin >> x;
			//vec[i].PB(x);
			peo.PB({x, {i, j+1}});
		}
	}
	sort(all(peo));
	int lo = 0, hi = sz(peo) + 1;
	while(hi - lo > 1){
		memset(don, 0, sizeof don);
		int mid = (lo + hi) >> 1;
		int tim = 0;
		bool can = true;
		for(auto per : peo){
			if(per.L >= mid)
				break;
			if(per.R.R <= don[per.R.L])
				continue;
			tim += per.R.R - don[per.R.L];
			if(tim > per.L)
				can = false;
			don[per.R.L] = per.R.R;
		}
		if(can)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
	return 0;
}
