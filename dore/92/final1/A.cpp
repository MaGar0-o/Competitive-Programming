//sobskdrbhvk
//task: boshke haye simaan
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
	cin >> q;
	for(int i = 0; i < q; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		quer.PB(MP(th, MP(fi, fi + se / th)));
		quer.PB(MP(se % th, MP(fi + se / th, fi + se / th + 1)));
		all.PB(fi);
		all.PB(fi + se / th);
		all.PB(fi + se / th + 1);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(auto x){

	}
	return 0;
}
