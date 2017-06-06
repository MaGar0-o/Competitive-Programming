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

LL ans = 0;
const LL Mod = 10859;
const int n = 7;
int cnt[n];

void build(int c = 0){
	if(c == n){
		ans++;
		if(ans >= Mod)
			ans -= Mod;
		return;
	}
	for(int i = 0; i < n; i++) if(cnt[i] < 3){
		cnt[i]++;
		for(int j = i + 1; j < n; j++) if(cnt[j] < 3){
			cnt[j]++;
			for(int k = j + 1; k < n; k++) if(cnt[k] < 3){
				cnt[k]++;
				build(c + 1);
				cnt[k]--;
			}
			cnt[j]--;
		}
		cnt[i]--;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	build();
	cout << ans << endl;
	return 0;
}
