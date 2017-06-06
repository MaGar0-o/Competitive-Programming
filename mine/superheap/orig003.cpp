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

const int maxn = 3e5 + 10;
set<int> mod;
int n;
LL ans = 0;
LL k;
int seg[maxn<<2],
	a[maxn],
	org[maxn];

int merge(int l, int r){
	if(l > r) swap(l, r);
	if(l == -1) return r;
	if(a[l] < a[r]) return l;
	return r;
}

int build(int l = 0, int r = n, int id = 1){
	if(r - l == 1)
		return seg[id] = l;
	int mid = (l + r) >> 1;
	return seg[id] = merge(build(l, mid, id<<1|0),
			build(mid, r, id<<1|1));
}

void modify(int idx, int l = 0, int r = n, int id = 1){
	if(idx < l or idx >= r or r - l == 1) return;
	int mid = (l + r) >> 1;
	modify(idx, l, mid, id<<1|0);
	modify(idx, mid, r, id<<1|1);
	seg[id] = merge(seg[id<<1|0],
			seg[id<<1|1]);
}

int get(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l) return -1;
	if(st <= l and r <= en) return seg[id];
	int mid = (l + r) >> 1;
	return merge(get(st, en, l, mid, id<<1|0), get(st, en, mid, r, id<<1|1));
}

void go(LL id, bool fi = true){
	LL chL = id * k + 1;
	if(chL >= n) return;
	LL chR = min(LL(n), chL + k);
	if(fi)
		for(int i = chL; i < chR; i++)
			go(i);
	int mid = get(chL, chR);
	if(a[id] > a[mid]){
		mod.insert(id);
		mod.insert(mid);
		swap(a[id], a[mid]);
		modify(id);
		modify(mid);
		go(mid, false);
		ans++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		org[i] = a[i];
	}
	build();
	for(k = 2; k < n; k++){
		mod.clear();
		go(0);
		for(auto id : mod)
			a[id] = org[id], modify(id);
	}
	cout << ans << endl;
	return 0;
}
