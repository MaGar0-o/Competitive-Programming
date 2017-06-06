//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
#define hash HASH

const int maxn = 3e5 + 85 - 69;
const LL Mod = 1000LL * 1000 * 1000 + 7,
	  base = 313;
vector<LL> hash[maxn];
string s[maxn];
LL P[maxn];

LL H(int id, int st, int en){
	return ((hash[id][en] - hash[id][st] * P[en - st]) % Mod + Mod) % Mod;
}

int lcp(pii a, pii b){
	int lo = 0, hi = min(sz(s[a.L]) - a.R, sz(s[b.L]) - b.R) + 1;
	while(hi - lo > 1){
		int mid = (lo+hi)>>1;
		if(H(a.L, a.R, a.R + mid) == H(b.L, b.R, b.R + mid))
			lo = mid;
		else
			hi = mid;
	}
	//cout << "Q(" << a.L << ' ' << a.R << ", " << b.L << ' ' << b.R << ") = " << lo << endl;
	return lo;
}

struct cmp{
	bool operator()(const pii &a, const pii &b)const{
		int len = lcp(a, b);
		if(a.R + len == sz(s[a.L])){
			if(b.R + len == sz(s[b.L]))
				return a.L > b.L;
			return true;
		}
		if(b.R + len == sz(s[b.L]))
			return false;
		return s[a.L][a.R + len] < s[b.L][b.R + len];
	}
};

using ordered_set = tree<pii, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set suf;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++){
		int ty;
		cin >> ty >> s[q];
		string &str = s[q];
		hash[q].PB(0);
		for(int i = 0; i < sz(str); i++)
			hash[q].PB((hash[q].back() * base + str[i]) % Mod);
		pii tmp(q, 0);
		//suf.order_of_key(tmp);
		if(ty == 1)
			for(int i = 0; i < sz(str); i++, tmp.R++)
				suf.insert(tmp);
		else if(ty == 2)
			for(int i = 0; i < sz(str); i++, tmp.R++)
				suf.erase(tmp);
		else{
			//cout << suf.lower_bound(tmp)->L << ' ' << suf.lower_bound(tmp)->R << endl;
			int idl = suf.order_of_key(tmp);
			str[sz(str) - 1]++;
			hash[q].pop_back();
			hash[q].PB((hash[q].back() * base + str.back()) % Mod);
			int idr = suf.order_of_key(tmp);
			cout << idr <<' ' <<  idl << endl;
		}
		cout << "#" << sz(suf) << endl;
		for(auto it : suf)
			cout << '@' << it.L << ' ' << it.R << endl;
	}
	return 0;
}
