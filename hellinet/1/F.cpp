//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 2e5 + 10;
const int maxsq = 2000;
int a[maxn],
	b[maxn],
	c[maxn],
	apos[maxn],
	fen[2][maxn],
	hlp[maxn],
	n;
ordered_set<int> seg[maxn / maxsq + 10];

void add(int idx, int val){
	seg[idx/maxsq].insert(val);
	hlp[idx] = val;
}

int get(int en, int val){
	int sqid = en / maxsq;
	int ret = 0;
	for(int i = 0; i < sqid; i++)
		ret += seg[i].order_of_key(val);
	for(int i = en - (en % maxsq); i < en; i++)
		ret += hlp[i] < val;
	return ret;
}

int fget(int fid, int idx){
	int ret = 0;
	for(idx++; idx; idx -= idx & -idx)
		ret += fen[fid][idx];
	return ret;
}

void fadd(int fid, int idx){
	for(idx++; idx < maxn; idx += idx & -idx)
		fen[fid][idx]++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(hlp, 63, sizeof hlp);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i], a[i]--, apos[a[i]] = i;
		cin >> b[i], b[i]--;
		cin >> c[i], c[i]--;
	}
	LL ans = 0;
	for(int i = n - 1; i >= 0; i--){
		int id = apos[i];
		ans += fget(0, b[id]);
		ans += fget(1, c[id]);
		ans -= get(b[id], c[id]);
		add(b[id], c[id]);
		fadd(0, b[id]);
		fadd(1, c[id]);
	}
	cout << ans << endl;
	return 0;
}
