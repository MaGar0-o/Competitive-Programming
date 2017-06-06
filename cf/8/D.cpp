//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef complex<LD> point;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

#define X real()
#define Y imag()

point C, H, S;
LD t1, t2;

void input(point &A){
	int fi, se;
	cin >> fi >> se;
	A = point(fi, se);
	return;
}

LD len(point A){
	return sqrt(A.X * A.X + A.Y * A.Y);
}

bool check(LD fr){
	if(t1 - fr < 0 or t2 - fr < 0) return false;
	return len(H - S) <= t1 + t2 - 2 * fr;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(9);
	cin >> t1 >> t2;
	swap(t1, t2);
	input(C);
	input(H);
	input(S);
	if(len(S - C) + len(H - S) <= len(H - C) + t1){
		cout << fixed << min(len(S - C) + len(H - S) + t2, len(H - C) + t1) << '\n';
		return 0;
	}
	t1 += len(H - C);
	t2 += len(S - C);
	LD lo = 0, hi = 1000;
	for(int i = 0; i < 10000; i++){
		LD mid = (lo + hi) / 2.;
		if(check(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << fixed << lo << '\n';
	return 0;
}
