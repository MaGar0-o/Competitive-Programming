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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> ty[i] >> q1[i];
		if(ty[i] == '~'){
			cin >> q2[i] >> q3[i];
			all.PB(MP(q1[i], i));
		}
	}
	sort(all(all));
	for(int i = 0; i < n; i++){
		if(ty[i] == '?'){
			int j, ans = 1;
			for(j = 0; j + maxsq <= sz(all) and all[min(sz(all), j + maxsq) - 1].L < q1[i]; j += maxsq)
				ans = (mp[j/maxsq][ans] ? mp[j/maxsq][ans] : ans);
			for(; j < sz(all) and all[j].L < q1[i]; j++)
				if(q2[all[j].R] == ans) ans = q3[all[j].R];
			cout << ans << '\n';
		}
		else{
			
		}
	}
	return 0;
}
