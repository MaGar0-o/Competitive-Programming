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

const LL e6 = 1000 * 1000;
const LL e12 = e6 * e6;
vector<LL> vec,
	sum;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		LL fi, se, th;
		cin >> fi >> se >> th;
		vec.PB(th + se * e6 + fi * e12);
	}
	sort(all(vec));
	sum.PB(0);
	for(auto num : vec)
		sum.PB(sum.back() + num);
	LL ans = e6 * e12 * 4;
	for(int i = 0; i < n; i++){
		LL cur = 0;
		cur += i * vec[i] - sum[i];
		cur += 12 * e12 * (n - i - 1) - ((sum.back() - sum[i + 1]) - vec[i] * (n - i - 1));
		smin(ans, cur);
	}
	cout << ans / e12 << ' ' << (ans % e12) / e6 << ' ' << ans % e6 << '\n';
	return 0;
}
