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

const int maxn = 1e5 + 85 - 69;
char ty[maxn];
LL cnt[maxn];
int n;

void solve(void){
	scanf("%d", &n);
	//cin >> n;
	LL bsu = 0,
	   wsu = 0;
	for(int i = 0; i < n; i++){
		scanf("%I64d %c", cnt + i, ty + i);
		//cin >> cnt[i] >> ty[i];
		if(ty[i] == 'B') bsu += cnt[i];
		else wsu += cnt[i];
	}
	if(bsu == 0 or wsu == 0){
		//cout << bsu+wsu << '\n';
		printf("%I64d\n", bsu + wsu);
		return;
	}
	LL soor = wsu/__gcd(wsu, bsu),
	   makh = bsu/__gcd(bsu, wsu);
	//cerr << soor << '/' << makh << endl;
	LL ans = 0;
	LL w = 0,
	   b = 0;
	for(int pos = 0; pos < n; pos++){
		int i = pos;
		if(ty[pos] == 'B'){
			if(w == 0 or w % soor){
				b += cnt[i];
				continue;
			}
			LL bneed = w / soor * makh - b;
			if(bneed < 0 or cnt[i] < bneed){
				b += cnt[i];
				continue;
			}
			cnt[i] -= bneed;
			ans++, w = 0, b = cnt[i];
	//		cout << "@" << pos << endl;
			continue;
		}
		if(b == 0 or b % makh){
			w += cnt[i];
			continue;
		}
		LL wneed = b / makh * soor - w;
		if(wneed < 0 or cnt[i] < wneed){
			w += cnt[i];
			continue;
		}
		cnt[i] -= wneed;
		ans++, w = cnt[i], b = 0;
	//	cout << "#" << pos << endl;
	}
	if(w or b) assert(0);
	printf("%d\n", int(ans));
	//cout << ans << '\n';
	return;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0); cin.tie(0);
	int t;
	//cin >> t;
	scanf("%d\n", &t);
	while(t--)
		solve();
	return 0;
}
