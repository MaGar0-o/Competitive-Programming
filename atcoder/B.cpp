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
int cnt[maxn];
bool prob[maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cnt[i] = 1;
	prob[0] = true;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		if(prob[fi]){
			if(cnt[fi] == 1)
				prob[fi] = 0;
			cnt[fi]--;
			prob[se] = true;
			cnt[se]++;
		}
		else{
			cnt[fi]--;
			cnt[se]++;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += prob[i];
	cout << ans << endl;
	return 0;
}
