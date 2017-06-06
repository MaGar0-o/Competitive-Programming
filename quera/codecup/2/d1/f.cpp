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

const int maxn = 1e6 + 85 - 69,
	  maxl = 21;
int a[maxn],
	q1[maxn],
	q2[maxn],
	spt[maxl][maxn],
	pp[maxn],
	stc[maxn],
	ans[maxn],
	n, q, sz;
vector<int> quer[maxn];

int merge(int i, int j){
	return a[i] < a[j] ? j : i;
}

void build(void){
	pp[0] = -1;
	for(int i = 1; i < maxn; i++)
		pp[i] = pp[i>>1]+1;
	for(int i = 0; i < n; i++)
		spt[0][i] = i;
	for(int i = 1; i < maxl; i++)
		for(int j = 0; j + (1 << i) <= n; j++)
			spt[i][j] = merge(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);
	return;
}

int get_max(int st, int en){
	int f = pp[en - st];
	return merge(spt[f][st], spt[f][en - (1 << f)]);
}

int get_fir(int st, int en, int val){
	int lo = st - 1,
		hi = en;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(a[get_max(st, mid + 1)] <= val)
			lo = mid;
		else
			hi = mid;
	}
	return hi < en ? hi : -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	build();
	for(int i = 0; i < q; i++){
		cin >> q1[i<<1] >> q2[i<<1] >> q1[i<<1|1] >> q2[i<<1|1];
		q1[i<<1]--, q1[i<<1|1]--;
		quer[q1[i<<1]].PB(i<<1|0);
		int val = a[get_max(q1[i<<1], q2[i<<1])];
		int id = get_fir(q1[i<<1|1], q2[i<<1|1], val);
		q1[i<<1|1] = id;
		if(~id) quer[id].PB(i<<1|1);
	}
	stc[sz++] = n;
	for(int i = n - 1; i >= 0; i--){
		while(stc[sz - 1] != n and a[i] >= a[stc[sz - 1]]) sz--;
		stc[sz++] = i;
		for(auto id : quer[i]){
			int lo = 0, hi = sz - 1;
			while(hi - lo > 1){
				int mid = (lo + hi) >> 1;
				if(stc[mid] < q2[id])
					hi = mid;
				else
					lo = mid;
			}
			ans[id] = sz - hi;
		}
	}
	for(int i = 0; i < q; i++)
		cout << ans[i<<1] + ans[i<<1|1] << '\n';
	return 0;
}
