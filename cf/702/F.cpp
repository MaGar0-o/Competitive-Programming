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

pll get_ptm(int pos, LL mon){
	int id = upper_bound(all(vecsum[pos]), mon) - vecsum[pos].begin();
	int lo = -1, hi = 
}

int find_can_pos(int pos, LL mon){
	int lo = -1, hi = pos + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(get_min(mid, pos + 1) > mon)
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}

void solve(LL mon){
	int ret = 0;
	int pos = find_can_pos(sz(allq) - 1, mon);
	while(pos >= 0){
		int ptr = find_get_pos(pos, mon);
		mon -= sum[pos + 1] - sum[ptr];
		ret += cnt[pos + 1] - cnt[ptr];
		if(ptr > 0){
			pll tmp = get_ptm(ptr - 1, mon);
			mon -= tmp.R;
			cnt += tmp.L;
		}
		else
			return ret;
		pos = find_can_pos(ptr - 2, mon);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(mnn, 63, sizeof mnn);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		allq.PB(b[i]);
	}
	sort(all(allq));
	allq.resize(unique(all(allq)) - allq.begin());
	for(int i = 0; i < n; i++){
		b[i] = lower_bound(all(allq), b[i]) - allq.begin();
		vec[b[i]].PB(a[i]);
		sum[b[i]+1] += a[i];
		cnt[b[i]+1]++;
		modify(b[i], a[i]);
	}
	for(int i = 0; i < sz(allq); i++){
		sort(all(vec[i]));
		vecsum[i].PB(0);
		for(int j = 0; j < sz(vec[i]); j++)
			vecsum[i].PB(vecsum[i].back() + vec[i][j]);
		sum[i + 1] += sum[i];
		cnt[i + 1] += cnt[i];
	}
	int q;
	cin >> q;
	while(q--){
		LL mon;
		cin >> mon;
		cout << solve(mon) << '\n';
	}
	return 0;
}
