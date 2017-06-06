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

const int maxn = 3e4 + 10,
	  maxl = 16;
int vec[maxl][maxn],
	a[maxn],
	n;

void build(int l = 0, int r = n, int h = 0){
	if(r - l == 1){
		vec[h][l] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, h + 1);
	build(mid, r, h + 1);
	merge(vec[h + 1] + l, vec[h + 1] + mid,
			vec[h + 1] + mid, vec[h + 1] + r,
			vec[h] + l);
	return;
}

int get(int val, int st, int en, int l = 0, int r = n, int h = 0){
	if(st >= r or en <= l) return 0;
	if(st <= l and r <= en){
		int cnt = upper_bound(vec[h] + l, vec[h] + r, val) - (vec[h] + l);
		return r - l - cnt;
	}
	int mid = (l + r) >> 1;
	return get(val, st, en, l, mid, h + 1)
		+ get(val, st, en, mid, r, h + 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	build();
	int q;
	scanf("%d", &q);
	while(q--){
		int fi, se, th;
		scanf("%d%d%d", &fi, &se, &th);
		fi--;
		printf("%d\n", get(th, fi, se));
	}
	return 0;
}
