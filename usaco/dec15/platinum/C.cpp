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

const int maxn = 2e5 + 85 - 69;
const LL INF = 1e18;
LL sum[maxn * 4],
   mini[maxn * 4],
   laz[maxn * 4];
int n, q;

void push(int, int, int);

void add(LL val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		sum[id] += (r - l) * val;
		mini[id] += val;
		laz[id] += val;
		return;
	}
	if(laz[id]) push(l, r, id);
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id * 2 + 0);
	add(val, st, en, mid, r, id * 2 + 1);
	sum[id] = sum[id * 2 + 0] + sum[id * 2 + 1];
	mini[id] = min(mini[id * 2 + 0], mini[id * 2 + 1]);
	return;
}

LL getmin(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return INF;
	if(st <= l and r <= en)
		return mini[id];
	if(laz[id]) push(l, r, id);
	int mid = (l + r) >> 1;
	return min(getmin(st, en, l, mid, id * 2 + 0),
			getmin(st, en, mid, r, id * 2 + 1));
}

LL getsum(int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return sum[id];
	if(laz[id]) push(l, r, id);
	int mid = (l + r) >> 1;
	return getsum(st, en, l, mid, id * 2 + 0)
		+ getsum(st, en, mid, r, id * 2 + 1);
}

void push(int l, int r, int id){
	int mid = (l + r) >> 1;
	add(laz[id], l, mid, l, mid, id * 2 + 0);
	add(laz[id], mid, r, mid, r, id * 2 + 1);
	laz[id] = 0;
	return;
}

int main(){
	ifstream cin("haybales.in");
	ofstream cout("haybales.out");
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		LL x;
		cin >> x;
		add(x, i, i + 1);
	}
	for(int i = 0; i < q; i++){
		char ty;
		int fi, se, th;
		cin >> ty >> fi >> se, fi--;
		if(ty == 'P'){
			cin >> th;
			add(th, fi, se);
		}
		else if(ty == 'M')
			cout << getmin(fi, se) << '\n';
		else
			cout << getsum(fi, se) << '\n';
	}
	return 0;
}
