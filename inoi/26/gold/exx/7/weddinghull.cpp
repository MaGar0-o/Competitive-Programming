//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LD, bool> pdb;
typedef pair<LD, LD> pdd;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2e5 + 10;
const LD zero = 0,
	  Eps = 1e-5;
int seg[maxn * 4],
	laz[maxn * 4];
vector<pair<pdb, pdd> > eve;
vector<LD> yall;
LD x[maxn],
   y[maxn],
   A, B, a, b;
int n;

void addrect(LD x, LD y, LD xx, LD yy){
	smax(x, zero);
	smin(xx, a);
	smax(y, zero);
	smin(yy, b);
	//cout << "#" << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
	if(x >= xx or y >= yy) return;
	//cout << "#> " << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
	eve.PB(MP(MP(x, 0), MP(y, yy)));
	eve.PB(MP(MP(xx, 1), MP(y, yy)));
	yall.PB(y);
	yall.PB(yy);
	return;
}

void add(int val, int st, int en, int l = 0, int r = sz(yall) - 1, int id = 1){
	if(st >= r or en <= l) return;
	if(st <= l and r <= en){
		laz[id] += val;
		seg[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id<<1|0);
	add(val, st, en, mid, r, id<<1|1);
	seg[id] = laz[id] + min(seg[id<<1|0], seg[id<<1|1]);
	return;
}

void solve(void){
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	LD lo = 0, hi = min(A, B) / 2.;
	for(int turn = 0; turn < 100; turn++){
		memset(seg, 0, sz(yall) * 4 * 4);
		memset(laz, 0, sz(yall) * 4 * 4);
		eve.clear();
		yall.clear();
		LD mid = (lo+hi)/2.;
		a = A - 2 * mid;
		b = B - 2 * mid;
		for(int i = 0; i < n; i++){
			addrect(x[i] - mid, y[i] - 2 * mid, x[i], y[i]);
			addrect(x[i] - 2 * mid, y[i] - mid, x[i] - mid, y[i]);
		}
		yall.PB(0);
		yall.PB(b);
		sort(all(eve));
		sort(all(yall));
		yall.resize(unique(all(yall)) - yall.begin());
		/*cout << a << ' ' << b << endl;
		for(auto q : eve)
			cout << q.L.L << ' ' << q.L.R << ' ' << q.R.L << ' ' << q.R.R << endl;
		*/	
		bool can = false;
		/*cout << "Y: ";
		for(auto y : yall)
			cout << y << ' ';
		cout << endl;*/
		for(int i = 0; i < sz(eve);){
			int ptr;
			for(ptr = i; ptr < sz(eve) and eve[ptr].L.L == eve[i].L.L; ptr++){
				auto q = eve[ptr];
				if(q.L.L >= a)
					goto hell;
				int yd = lower_bound(all(yall), q.R.L) - yall.begin(),
					yu = lower_bound(all(yall), q.R.R) - yall.begin();
				//cout << q.L.L << ' ' << q.L.R << ' ' << q.R.L << ' ' << q.R.R << endl;
				//cout << yd << ' ' << yu << endl;;
				if(q.L.R == 0)
					add(+1, yd, yu);
				else
					add(-1, yd, yu);
			}
			i = ptr;
			if(seg[1] == 0)
				can = true;
		}
hell:
		if(can or !sz(eve) or eve[0].L.R > Eps) lo = mid;
		else hi = mid;
	}
	//cout << "#" << lo << endl;
	cout << 3 * lo * lo << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(2);
	while(cin >> n >> B >> A and n) solve();
	return 0;
}
