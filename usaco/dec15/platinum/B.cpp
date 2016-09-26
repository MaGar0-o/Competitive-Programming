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
int seg1[maxn * 4],
	seg2[maxn * 4],
	laz1[maxn * 4],
	laz2[maxn * 4];
int a[maxn],
	dp[maxn],
	pd[maxn];
bool mark[maxn];
vector<int> vec;
int n;

void propagate1(int);
void propagate2(int);

void inc1(int val, int st, int en, int l = 0, int r = n, int id = 1){
	if(r <= st or en <= l)
		return;
	if(st <= l and r <= en){
		seg1[id] += val;
		laz1[id] += val;
		return;
	}
	if(laz1[id]) propagate1(id);
	int mid = (l + r) >> 1;
	inc1(val, st, en, l, mid, id * 2 + 0);
	inc1(val, st, en, mid, r, id * 2 + 1);
	seg1[id] = min(seg1[id * 2 + 0], seg1[id * 2 + 1]);
	return;
}

int min1(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return maxn * 10;
	if(st <= l and r <= en)
		return seg1[id];
	if(laz1[id]) propagate1(id);
	int mid = (l + r) >> 1;
	return min(min1(st, en, l, mid, id * 2 + 0),
			min1(st, en, mid, r, id * 2 + 1));
}

void propagate1(int id){
	inc1(laz1[id], 0, 1, 0, 1, id * 2 + 0);
	inc1(laz1[id], 0, 1, 0, 1, id * 2 + 1);
	laz1[id] = 0;
	return;
}

void inc2(int val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg2[id] += val;
		laz2[id] += val;
		return;
	}
	if(laz2[id]) propagate2(id);
	int mid = (l + r) >> 1;
	inc2(val, st, en, l, mid, id * 2 + 0);
	inc2(val, st, en, mid, r, id * 2 + 1);
	seg2[id] = min(seg2[id * 2 + 0], seg2[id * 2 + 1]);
	return;
}

int min2(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return maxn * 10;
	if(st <= l and r <= en)
		return seg2[id];
	if(laz2[id])
		propagate2(id);
	int mid = (l + r) >> 1;
	return min(min2(st, en, l, mid, id * 2 + 0),
			min2(st, en, mid, r, id * 2 + 1));
}

void propagate2(int id){
	inc2(laz2[id], 0, 1, 0, 1, id * 2 + 0);
	inc2(laz2[id], 0, 1, 0, 1, id * 2 + 1);
	laz2[id] = 0;
	return;
}

void calc1(void){
	for(int i = 1; i <= n; i++)
		inc1(-1, n - i, n);
	for(int i = 1; i <= n; i++){
		int id = lower_bound(all(vec), a[i - 1]) - vec.begin();
		inc1(+1, id, n);
		int lo = 0, hi = n + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(min1(n - mid, n) + n - mid >= 0)
				lo = mid;
			else
				hi = mid;
		}
		dp[i] = lo;
	}
	return;
}

void calc2(void){
	for(int i = 1; i <= n; i++)
		inc2(-1, 0, i);
	for(int i = n; i >= 1; i--){
		int id = lower_bound(all(vec), a[i - 1]) - vec.begin();
		inc2(+1, 0, id);
		int lo = 0, hi = n + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(min2(0, mid) + n - mid >= 0)
				lo = mid;
			else
				hi = mid;
		}
		pd[i] = lo;
	}
	return;
}

int main(){
	ifstream cin("cardgame.in");
	ofstream cout("cardgame.out");
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], mark[--a[i]] = true;
	for(int i = 0; i < n + n; i++)
		if(!mark[i])
			vec.PB(i);
	calc1();
	calc2();
	int ans = 0;
	for(int i = 0; i <= n; i++)
		smax(ans, dp[i] + pd[i + 1]);
	cout << ans << endl;
	return 0;
}
