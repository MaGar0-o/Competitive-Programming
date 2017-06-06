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

const int maxn = 5e5 + 10,
	  maxl = 20;
int a[maxn],
	ty[maxn],
	fi[maxn],
	se[maxn],
	tmp[maxn],
	n, q;
LL fen[maxl][maxn];
pii segvec[maxl][maxn];
vector<pii> prs;
set<int> vec[maxn];
vector<LL> all;

void build(int l = 0, int r = sz(prs), int h = 0){
	if(r - l == 1){
		segvec[h][l] = MP(prs[l].R, prs[l].L);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, h+1);
	build(mid, r, h+1);
	merge(segvec[h + 1] + l, segvec[h + 1] + mid,
			segvec[h + 1] + mid, segvec[h + 1] + r,
			segvec[h] + l);
	return;
}

void fenadd(int h, int idx, LL val){
	//cout << "@" << idx << ' ' << val << endl;
	idx++;
	while(idx <= sz(prs)){
		fen[h][idx] += val;
		idx += idx & -idx;
	}
	return;
}

void add(int idx, LL val, int l = 0, int r = sz(prs), int h = 0){
	//cout << "#" << h << endl;
	if(idx >= r or idx < l)
		return;
	int id = lower_bound(segvec[h] + l, segvec[h] + r, MP(prs[idx].R, prs[idx].L)) - segvec[h];
	fenadd(h, id, val);
	if(r - l == 1)
		return;
	int mid = (l + r) >> 1;
	add(idx, val, l, mid, h+1);
	add(idx, val, mid, r, h+1);
	return;
}

LL fenget(int h, int idx){
	LL ret = 0;
	while(idx){
		ret += fen[h][idx];
		idx -= idx & -idx;
	}
	return ret;
}

LL fenget(int h, int st, int en){
	return fenget(h, en) - fenget(h, st);
}

LL get(int val, int st, int en, int l = 0, int r = sz(prs), int h = 0){
	if(st >= r or en <= l)
		return 0;
	if(st <= l and r <= en){
		int id = lower_bound(segvec[h] + l, segvec[h] + r, MP(val, -10)) - segvec[h];
		//cout << "?" << id << endl;
		return fenget(h, l, id);
	}
	int mid = (l + r) >> 1;
	return get(val, st, en, l, mid, h+1)
		+ get(val, st, en, mid, r, h+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] % 3)
			a[i] = 0;
		all.PB(a[i]);
	}
	for(int i = 0; i < q; i++){
		cin >> ty[i] >> fi[i] >> se[i];
		fi[i]--;
		if(ty[i] == 0){
			if(se[i] % 3) se[i] = 0;
			all.PB(se[i]);
		}
	}
	all.PB(0);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < sz(all); i++)
		vec[i].insert(-1);
	for(int i = 0; i < n; i++){
		a[i] = lower_bound(all(all), a[i]) - all.begin();
		prs.PB(MP(i, *vec[a[i]].rbegin()));
		vec[a[i]].insert(i);
	}
	for(int i = 0; i < sz(all); i++)
		vec[i].insert(n);
	memcpy(tmp, a, sizeof a);
	for(int i = 0; i < q; i++) if(!ty[i]){
		se[i] = lower_bound(all(all), se[i]) - all.begin();
		//fix here :(
		vec[tmp[fi[i]]].erase(fi[i]);
		auto it = vec[tmp[fi[i]]].lower_bound(fi[i]);
		auto it2 = it;
		it2--;
		if(*it != n)
			prs.PB(MP(*it, *it2));

		tmp[fi[i]] = se[i];
		it = vec[tmp[fi[i]]].lower_bound(fi[i]);
		it2 = it;
		it2--;
		if(*it != n)
			prs.PB(MP(*it, fi[i]));
		prs.PB(MP(fi[i], *it2));
		vec[se[i]].insert(fi[i]);
	}
	sort(all(prs));
	prs.resize(unique(all(prs)) - prs.begin());
	/*cout << "prs:\n";
	for(auto P : prs)
		cout << P.L << ' ' << P.R << endl;*/
	for(int i = 0; i < sz(all); i++)
		vec[i].clear(), vec[i].insert(-1);
	build();
	for(int i = 0; i < n; i++){
		int lst = *vec[a[i]].rbegin();
		int id = lower_bound(all(prs), MP(i, lst)) - prs.begin();
		//cout << id << endl;
		add(id, all[a[i]]);
		vec[a[i]].insert(i);
	}
	for(int i = 0; i < sz(all); i++)
		vec[i].insert(n);
	for(int i = 0; i < q; i++){
		if(ty[i]){
			int idl = lower_bound(all(prs), MP(fi[i], -10)) - prs.begin(),
				idr = lower_bound(all(prs), MP(se[i], -10)) - prs.begin();
			cout << get(fi[i], idl, idr) << '\n';
		}
		else{
			vec[a[fi[i]]].erase(fi[i]);
			auto it = vec[a[fi[i]]].lower_bound(fi[i]);
			auto it2 = it;
			it2--;
			int id;
			if(*it != n){
				id = lower_bound(all(prs), MP(*it, fi[i])) - prs.begin();
				add(id, -all[a[*it]]);
				id = lower_bound(all(prs), MP(*it, *it2)) - prs.begin();
				add(id, +all[a[*it]]);
			}
			id = lower_bound(all(prs), MP(fi[i], *it2)) - prs.begin();
			add(id, -all[a[fi[i]]]);
			
			a[fi[i]] = se[i];
			it = vec[a[fi[i]]].lower_bound(fi[i]);
			it2 = it;
			it2--;
			if(*it != n){
				id = lower_bound(all(prs), MP(*it, *it2)) - prs.begin();
				add(id, -all[a[*it]]);
				id = lower_bound(all(prs), MP(*it, fi[i])) - prs.begin();
				add(id, +all[a[*it]]);
			}
			id = lower_bound(all(prs), MP(fi[i], *it2)) - prs.begin();
			add(id, +all[a[fi[i]]]);
			vec[a[fi[i]]].insert(fi[i]);
		}
	}
	return 0;
}
