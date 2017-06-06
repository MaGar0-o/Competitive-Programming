//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef complex<LL> point;

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

const int maxn = 1e5 + 85 - 69;
point p[maxn];
int n;
deque<int> dq;

LL zcross(point A, point B){
	return A.X * B.Y - A.Y * B.X;
}

point rot90(point A){
	return point(-A.Y, A.X);
}

bool isleft(point A, point B, point C){
	return zcross(B - A, C - A) > 0;
}

bool left_turn(point A, point B, point C){
	return zcross(B - A, C - B) > 0;
}

bool right_turn(point A, point B, point C){
	return zcross(B - A, C - B) < 0;
}

void solve(void){
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		p[i] = point(fi, se);
	}
	bool can = true;
	while(sz(dq)) dq.pop_back();
	dq.push_front(n - 1);
	for(int i = n - 2; i >= 0 and can; i--){
		point perp = rot90(p[i + 1] - p[i]);
		for(int j = 0; j < min(sz(dq), 3); j++){
			if(isleft(p[i + 1], p[i + 1] + perp, p[dq[j]]))
				can = false;
			if(isleft(p[i + 1], p[i + 1] + perp, p[dq[sz(dq)-j-1]]))
				can = false;
		}
		if(!can) break;
		while(sz(dq) >= 2 and left_turn(p[i], p[dq[0]], p[dq[1]]))
			dq.pop_front();
		//cout << "HI" << i << endl;
		while(sz(dq) >= 2 and right_turn(p[i], p[dq[sz(dq) - 1]], p[dq[sz(dq) - 2]]))
			dq.pop_back();
		dq.push_front(i);
		dq.push_back(i);
	}
	if(can)
		cout << "Fair\n";
	else
		cout << "Unfair\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n and n)
		solve();
	return 0;
}
