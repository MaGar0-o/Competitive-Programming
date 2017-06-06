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

const int maxn = 5e5 + 85 - 69;
int a[maxn],
	nxt[maxn],
	lst[maxn],
	n;
set<pll> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	mark[0] = mark[n - 1] = true;
	int lp = 0,
		rp = n - 1;
	for(int i = 1; i < n - 1; i++)
		if(mark[i - 1] and a[i] >= a[i - 1])
			mark[i] = true, lp = i;
		else
			break;
	for(int i = n - 2; i >= 0; i--)
		if(mark[i + 1] and a[i] >= a[i + 1])
			mark[i] = true, rp = i;
		else
			break;
	for(int i = 1; i + 1 < n; i++)
		s.insert(MP(-min(a[i - 1], a[i + 1]), i));
	iota(lst, lst + maxn, -1);
	iota(nxt, nxt + maxn, +1);
	LL ans = 0;
	while(sz(s)){
		int id = s.begin()->R;
		ans -= s.begin()->L;
		s.erase(s.begin());
		if(lst[id]) s.erase(MP(-min(a[lst[lst[id]]], a[id]), lst[id]));
		if(nxt[id] < n - 1) s.erase(MP(-min(a[nxt[nxt[id]]], a[id]), nxt[id]));
		int idl = lst[id];
		int idr = nxt[id];
		nxt[idl] = idr;
		lst[idr] = idl;
		if(idl) s.insert(MP(-min(a[lst[idl]], a[idr]), idl));
		if(idr < n - 1) s.insert(MP(-min(a[nxt[idr]], a[idl]), idr));
	}
	cout << ans << endl;
	return 0;
}
