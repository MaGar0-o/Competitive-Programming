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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	//finding rights
	{
		int lo = 0,
		hi = n;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get(1, 1, mid, n) < 1)
				lo = mid;
			else
				hi = mid;
		}
		rx1 = hi;
		lo = 0, hi = n;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get(1, 1, mid, n) <= 1)
				lo = mid;
			else
				hi = mid;
		}
		rx2 = hi;
	}
	//finding lefts
	{
		int lo = 1, hi = n + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get(n, n, mid, 1) < 1)
				hi = mid;
			else
				lo = mid;
		}
		lx2 = lo;
		lo = 1, hi = n + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get(n, n, mid, 1) <= 1)
				hi = mid;
			else
				lo = mid;
		}
		lx1 = lo;
	}
	//finding ups
	{
		int lo = 0,
			hi = n;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get(1, 1, n, mid) < 1)
				lo = mid;
			else
				hi = mid;
		}
		uy1 = hi;
		lo = 0, hi = n;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get(1, 1, n, mid) <= 1)
				lo = mid;
			else
				hi = mid;
		}
		uy2 = hi;
	}
	//finding downs
	{
		int lo, hi;
		lo = 1, hi = n + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get(n, n, 1, mid) < 1)
				hi = mid;
			else
				lo = mid;
		}
		dy2 = hi;
		lo = 1, hi = n + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(get(n, n, 1, mid) <= 1)
				hi = mid;
			else
				lo = mid;
		}
		dy1 = hi;
	}
	if(lx1 > lx2) swap(lx1, lx2);
	if(rx1 > rx2) swap(rx1, rx2);
	if(uy1 > uy2) swap(uy1, uy2);
	if(dy1 > dy2) swap(dy1, dy2);
	check(lx1, rx1, dy1, uy1, lx2, rx2, dy2, uy2);
	check(lx1, rx2, dy1, uy1, lx2, lx1, 
	return 0;
}
