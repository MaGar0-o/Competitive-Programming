//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

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

const int maxn = 3e5 + 10;
int swp1[maxn * 20],
	swp2[maxn * 20],
	org[maxn],
	seg[maxn * 4],
	a[maxn],
	sz, n;
set<int> mod;

int merge(int id1, int id2){
	return (a[id1] < a[id2]) ? id1 : id2;
}

int get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l) assert(0);
	if(st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	if(en <= mid) return get(st, en, l, mid, id<<1|0);
	if(st >= mid) return get(st, en, mid, r, id<<1|1);
	return merge(get(st, en, l, mid, id<<1|0),
			get(st, en, mid, r, id<<1|1));
}

void modify(int idx, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r) return;	
	if(r - l == 1){
		seg[id] = idx;
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, l, mid, id<<1|0);
	modify(idx, mid, r, id<<1|1);
	seg[id] = merge(seg[id<<1|0], seg[id<<1|1]);
	return;
}

void seg_swap(int id1, int id2){
	if(min(id1, id2) < 0 or max(id1, id2) >= n) assert(0);
	swap(a[id1], a[id2]);
	modify(id1);
	modify(id2);
	return;
}

int build(int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		seg[id] = l;
		return id;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id<<1|0);
	build(mid, r, id<<1|1);
	seg[id] = merge(seg[id<<1|0], seg[id<<1|1]);
	return id;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		org[i] = a[i];
		//modify(i);
	}
	build();
	LL ans = 0;
	for(int k = 2; k < n; k++){
		for(int i = min(n / k + 10, n - 1); i >= 0; i--){
			int id = i;
			while(1){
				LL chL = 1LL * id * k + 1,
				   chR = min((LL)n - 1, 1LL * id * k + k);
				if(chL > chR)
					break;
				int mid = get(chL, chR + 1);
				if(a[mid] < a[id]){
					mod.insert(id);
					mod.insert(mid);
					seg_swap(id, mid);
					ans++;
				}
				else
					break;
				id = mid;
			}
		}
		for(auto id : mod)
			a[id] = org[id];
		for(auto id : mod)
			modify(id);
		mod.clear();
	}
	cout << ans << '\n';
	return 0;
}
