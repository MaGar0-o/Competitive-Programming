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

const int maxn = 4e4 + 85 - 69;
int n, d;

struct node{
	LL ans;
	LL tmp1, tmp2, tmp3;
} seg[maxn * 4];

void pull(int id){
	seg[id].ans = max(seg[id * 2 + 0].ans + seg[id * 2 + 1].tmp1,
			seg[id * 2 + 0].tmp2 + seg[id * 2 + 1].ans);
	seg[id].tmp1 = max(seg[id * 2 + 0].tmp3 + seg[id * 2 + 1].ans,
			seg[id * 2 + 0].tmp1 + seg[id * 2 + 1].tmp1);
	seg[id].tmp2 = max(seg[id * 2 + 0].ans + seg[id * 2 + 1].tmp3,
			seg[id * 2 + 0].tmp2 + seg[id * 2 + 1].tmp2);
	seg[id].tmp3 = max(seg[id * 2 + 0].tmp3 + seg[id * 2 + 1].tmp2,
			seg[id * 2 + 0].tmp1 + seg[id * 2 + 1].tmp3);
	return;
}

void modify(int idx, LL val, int l = 0, int r = n, int id = 1){
	if(idx >= r or idx < l)
		return;
	if(r - l == 1){
		seg[id].ans = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify(idx, val, l, mid, id * 2 + 0);
	modify(idx, val, mid, r, id * 2 + 1);
	pull(id);
	return;
}

int main(){
	ifstream cin("optmilk.in");
	ofstream cout("optmilk.out");
	cin >> n >> d;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		modify(i, x);
	}
	LL ans = 0;
	for(int i = 0; i < d; i++){
		int fi, se;
		cin >> fi >> se;
		fi--;
		modify(fi, se);
		ans += seg[1].ans;
	}
	cout << ans << endl;
	return 0;
}
