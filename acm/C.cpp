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
	int n, t = 0;
	while(cin >> n and n and ++t){
		vector<int> all;
		int cnt[n];
		int a[n][3];
		int s[3][n * 3];
		for(int i = 0; i < n; i++){
			cin >> cnt[i];
			for(int j = 0; j < cnt[i]; j++)
				cin >> a[i][j], all.PB(a[i][j]);
		}
		sort(all(all));
		all.resize(unique(all(all)) - all.begin());
		for(int i = 0; i < 3; i++)
			memset(s[i], 0, sz(all) * 4);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < cnt[i]; j++)
				s[j][a[i][j] = lower_bound(all(all), a[i][j]) - all.begin()]++;
		vector<int> ans;
		int mxsc = -1, mxs3 = -1, mxs2 = -1;
		for(int i = 0; i < sz(all); i++){
			int sc = 3 * s[0][i] + 2 * s[1][i] + 1 * s[2][i];
			if(sc > mxsc)
				mxsc = sc, mxs3 = s[0][i], mxs2 = s[1][i], ans.clear();
			else if(sc == mxsc and s[0][i] > mxs3)
				mxs3 = s[0][i], mxs2 = s[1][i], ans.clear();
			else if(sc == mxsc and s[0][i] == mxs3 and s[1][i] > mxs2)
				mxs2 = s[1][i], ans.clear();
			if(sc == mxsc and s[0][i] == mxs3 and s[1][i] == mxs2)
				ans.PB(all[i]);
		}
		for(int i = 0; i < sz(ans); i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}
