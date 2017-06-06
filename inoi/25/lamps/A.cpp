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

const int maxn = 1.5e6+10;
LL seg[maxn * 4],
   laz[maxn * 4];
set<pii> Set[maxn/3];
vector<int> all,
	alam;
char ty[maxn];
int q1[maxn],
	q2[maxn],
	q3[maxn];
int n, q;

int idof(int val, vector<int> &vec){
	return lower_bound(all(vec), val) - vec.begin();
}

void inc(LL, int, int, int, int, int);

void push(int l, int r, int id){
	int mid = (l + r) >> 1;
	inc(laz[id], l, mid, l, mid, id * 2 + 0);
	inc(laz[id], mid, r, mid, r, id * 2 + 1);
	laz[id] = 0;
	return;
}

void inc(LL val, int st, int en, int l = 0, int r = sz(all), int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[id] += val * (all[r] - all[l]);
		laz[id] += val;
		return;
	}
	if(laz[id]) push(l, r, id);
	int mid = (l+r)>>1;
	inc(val, st, en, l, mid, id * 2 + 0);
	inc(val, st, en, mid, r, id * 2 + 1);
	seg[id] = seg[id * 2 + 0] + seg[id * 2 + 1];
	return;
}

LL get(int st, int en, int l = 0, int r = sz(all), int id = 1){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en)
		return seg[id];
	if(laz[id]) push(l, r, id);
	int mid = (l + r) >> 1;
	return get(st, en, l, mid, id * 2 + 0)
		+ get(st, en, mid, r, id * 2 + 1);
}

void turnon(int x, int l, int r){
	set<pii> &s = Set[x];
	//cout << "(" << x << ") ";
	while(1){
		auto it = s.lower_bound(MP(l, 0));
		if(it == s.end() or it->L > r)
			break;
		inc(-1, it->L, it->R);
		smax(r, it->R);
		s.erase(it);
	}
	auto it = s.lower_bound(MP(l, 0));
	if(it != s.begin()){
		it--;
		if(it->R >= l){
			inc(-1, it->L, it->R);
			smin(l, it->L);
			smax(r, it->R);
			s.erase(it);
		}
	}
	inc(+1, l, r);
	s.insert(MP(l, r));
	//for(auto P : s)
	//	cout << "(" << all[P.L] <<", " << all[P.R] << ") ";
	//cout << endl;
	return;
}

void turnoff(int x, int l, int r){
	set<pii> &s = Set[x];
	//cout << "(" << x << ") ";
	while(1){
		auto it = s.lower_bound(MP(l, 0));
		if(it == s.end() or it->L >= r)
			break;
		inc(-1, it->L, it->R);
		pii an = *it;
		s.erase(it);
		if(it->R > r){
			inc(+1, r, an.R);
			s.insert(MP(r, an.R));
		}
	}
	auto it = s.lower_bound(MP(l, 0));
	if(it != s.begin()){
		it--;
		if(it->R > l){
			inc(-1, it->L, it->R);
			auto an = *it;
			s.erase(it);
			s.insert(MP(an.L, l));
			inc(+1, an.L, l);
			if(an.R > r){
				s.insert(MP(r, an.R));
				inc(+1, r, an.R);
			}
		}
	}
	//for(auto P : s)
	//	cout << "(" << all[P.L] <<", " << all[P.R] << ") ";
	//cout << endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		cin >> ty[i] >> q1[i] >> q2[i], q2[i]++;
		if(ty[i] != '?') cin >> q3[i];
		all.PB(q1[i]);
		all.PB(q2[i]);
		all.PB(q2[i]-1);
		alam.PB(q3[i]);
	}
	sort(all(all));
	sort(all(alam));
	all.resize(unique(all(all)) - all.begin());
	alam.resize(unique(all(alam)) - alam.begin());
	for(int i = 0; i < q; i++){
		q1[i] = idof(q1[i], all);
		q2[i] = idof(q2[i], all);
		q3[i] = idof(q3[i], alam);
		//cout << i << ": ";
		if(ty[i] == '+')
			turnon(q3[i], q1[i], q2[i]);
		else if(ty[i] == '-')
			turnoff(q3[i], q1[i], q2[i]);
		else
			cout << get(q1[i], q2[i]) << '\n';
	}
	return 0;
}
