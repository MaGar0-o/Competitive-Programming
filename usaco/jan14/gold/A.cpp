//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> Point;
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
#define x first
#define y second

const int maxn = 1e5 + 85 - 69;
Point P[2][maxn],
	  stc[maxn],
	  stc2[maxn];
int n, sz, sz2;
const int k = 200;

LL cross(Point A, Point B, Point C){
	B.L -= A.L;
	B.R -= A.R;
	C.L -= A.L;
	C.R -= A.R;
	return B.x * C.y - B.y * C.x;
}

bool check(Point &Po, int id){
	for(int i = id - k; i <= id + k; i++)
		if(cross(stc[(i + sz * k) % sz], stc[(i + 1 + sz * k) % sz], Po) < 0)
			return false;
	return true;
}

int find_id1(int lo, int hi, Point &A){
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(stc[mid].x <= A.x)
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int find_id2(int lo, int hi, Point &A){
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(stc[mid].x >= A.x)
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int solve(Point a[], Point b[]){
	sz = 0;
	stc[sz++] = a[0];
	for(int i = 1; i < n; i++){
		while(sz >= 2 and cross(stc[sz - 2], stc[sz - 1], a[i]) < 0)
			sz--;
		stc[sz++] = a[i];
	}
	for(int i = n - 2; i >= 0; i--){
		while(sz >= 2 and cross(stc[sz - 2], stc[sz - 1], a[i]) < 0)
			sz--;
		stc[sz++] = a[i];
	}
	sz--;
	sz2 = 0;
	stc2[sz2++] = stc[0];
	for(int i = 1; i < sz; i++){
		while(sz2 >= 2 and cross(stc2[sz2 - 2], stc2[sz2 - 1], stc[i]) == 0)
			sz2--;
		stc2[sz2++] = stc[i];
	}
	for(int i = 0; i < sz2; i++)
		stc[i] = stc2[i];
	sz = sz2;
	int upp = 1;
	while(upp < sz and stc[upp].x > stc[upp - 1].x) upp++;
	int ret = 0;
	for(int i = 0; i < n; i++){
		int id1 = find_id1(0, upp, b[i]),
			id2 = find_id2(upp, sz, b[i]);
		ret += check(b[i], id1) and check(b[i], id2);
	}
	return ret;
}

int main(){
	ifstream cin("curling.in");
	ofstream cout("curling.out");
	cin >> n;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			int fi, se;
			cin >> fi >> se;
			P[i][j] = Point(fi, se);
		}
		sort(P[i], P[i] + n);
	}
	cout << solve(P[0], P[1]) << ' '
		<< solve(P[1], P[0]) << '\n';
	return 0;
} 
