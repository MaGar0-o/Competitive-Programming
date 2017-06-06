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

const int maxn = 3e5 + 85 - 69;
LL t[maxn],
	w[maxn],
	ord[maxn],
	n, t0, w0;
multiset<LL> s;

bool cmp(int i, int j){
	return t[i] > t[j];
}

bool can(int bet){
	s.clear();
	LL hav = t0;
	int ptr =0;
	while(ptr < n and t[ord[ptr]] > hav){
		LL val = w[ord[ptr]] - t[ord[ptr]];
		s.insert(val);
		if(sz(s) > bet){
			hav -= *s.begin();
			s.erase(s.begin());
		}
		if(hav < 0) return false;
		ptr++;
	}
	return hav >= 0;
}

int main(){
	scanf("%d%I64d%I64d", &n, &t0, &w0);
	n--;
	for(int i = 0; i < n; i++){
		scanf("%I64d%I64d", t + i, w + i);
		w[i]++;
	}
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	int lo = -1,
		hi = n + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(can(mid))
			hi = mid;
		else
			lo = mid;
	}
	printf("%d", hi + 1);
	return 0;
}
