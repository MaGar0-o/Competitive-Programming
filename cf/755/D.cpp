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

const int maxn = 1e6 + 10;
int all;
int n;
int fen[maxn];

void inc(int idx){
	all++;
	for(idx++; idx < maxn; idx += idx & -idx)
		fen[idx]++;
}

int get(int idx){
	int ret = 0;
	for(; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

int get(int st, int en){
	if(st >= n) st -= n;
	if(en >= n) en -= n;
	if(st <= en) return get(en + 1) - get(st);
	return all - get(en + 1, st - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> n >> k;
	int pos = 0;
	LL cnt = 1;
	for(int i = 0; i < n; i++){
		cnt += 1 + get(pos + 1, pos + k - 1);
		//cout << pos + 1 << ' ' << pos + k << ' ' << get(pos + 1, pos + k) << endl;
		cout << cnt << ' ';
		inc(pos);
		pos += k;
		if(pos >= n) pos -= n;
		inc(pos);
	}
	return 0;
}
