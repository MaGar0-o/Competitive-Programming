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
vector<pair<int, bool> > a, b;
int cnt1[maxn], cnt2[maxn];
int qx1[maxn],
	qx2[maxn],
	qy1[maxn],
	qy2[maxn];
int n, q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		char ty;
		int fi, se;
		cin >> ty >> fi >> se;
		a.PB(MP(fi, ty == '|'));
		b.PB(MP(se, ty == '-'));
	}
	sort(all(a));
	sort(all(b));
	cnt1[n - 1] = cnt2[n - 1] = 1;
	for(int i = n - 2; i >= 0; i--){
		cnt1[i] = cnt1[i + 1] + (a[i].R != a[i + 1].R);
		cnt2[i] = cnt2[i + 1] + (b[i].R != b[i + 1].R);
	}
	for(int i = 0; i < q; i++){
		cin >> qx1[i] >> qy1[i] >> qx2[i] >> qy2[i];
		int id1 = lower_bound(all(a), MP(qx1[i], false)) - a.begin(),
			id2 = lower_bound(all(a), MP(qx2[i], false)) - a.begin();
		int dx, dy;
		if(id1 > id2)
			dx = cnt1[id2] - cnt1[id1 - 1] + (a[id1 - 1].R);
		else if(id1 == id2)
			dx = 0;
		else
			dx = cnt1[id1] - cnt1[id2 - 1] + (a[id1].R);
		id1 = lower_bound(all(b), MP(qy1[i], false)) - b.begin();
		id2 = lower_bound(all(b), MP(qy2[i], false)) - b.begin();
		if(id1 > id2)
			dy = cnt2[id2] - cnt2[id1 - 1] + (b[id1 - 1].R);
		else if(id1 == id2)
			dy = 0;
		else
			dy = cnt2[id1] - cnt2[id2 - 1] + (b[id1].R);
		cout << max(dx, dy) << '\n';
	}
	return 0;
}
