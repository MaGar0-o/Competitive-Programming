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

#define NO return func(), 0
#define YES return cout << "yes\n", 0

pll pos[2][2];

int func(void) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (pos[0][i] == pos[1][j])
				YES;
	cout << "no\n";
	return 0;
}

bool ok(int st, int en, int l, int r) {
	if (st == l) return true;
	if (st > l)
		swap(st, l), swap(en, r);
	return l <= en;
}

void fix(pll &a, pll &b) {
	if (b < a)
		swap(a, b);
}

bool in(pll A, pll B, pll C) {
	fix(A, B);
	if (A.L == B.L)
		return C.L == A.L and A.R <= C.R and C.R <= B.R;
	if (A.R == B.R)
		return C.R == A.R and A.L <= C.L and C.L <= B.L;
}

int solve(void) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cin >> pos[i][j].L >> pos[i][j].R;
	fix(pos[0][0], pos[0][1]);
	fix(pos[1][0], pos[1][1]);
	if (pos[0][0] == pos[0][1]) {
		if (in(pos[1][0], pos[1][1], pos[0][0]))
			YES;
		else
			NO;
	}
	else if(pos[1][0] == pos[1][1]) {
		if (in(pos[0][0], pos[0][1], pos[1][1]))
			YES;
		else
			NO;
	}
	if (pos[0][0].L == pos[0][1].L) {
		if (pos[1][0].L != pos[0][0].L or pos[1][1].L != pos[0][0].L)
			NO;
		if (ok(pos[0][0].R, pos[0][1].R, pos[1][0].R, pos[1][1].R))
			YES;
		else
			NO;
	}
	else if (pos[0][0].R == pos[0][1].R) {
		if (pos[1][0].R != pos[0][0].R or pos[1][1].R != pos[0][0].R)
			NO;
		if (ok(pos[0][0].L, pos[0][1].L, pos[1][0].L, pos[1][1].L))
			YES;
		else
			NO;
	}
	else
		NO;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
