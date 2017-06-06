//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LD, LD> point;

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

const LD sq3 = sqrt(3);
point vec[4],
	  P[4];

point operator+(point A, point B){
	A.x += B.x;
	A.y += B.y;
	return A;
}

point operator-(point A, point B){
	A.x -= B.x;
	A.y -= B.y;
	return A;
}

point Conv(point A){
	A.y -= A.x / 2.;
	A.x *= sq3 / 2.;
	return A;
}

LD dot(point A, point B){
	return A.x * B.x + A.y * B.y;
}

LD zcross(point A, point B){
	return A.x * B.y - A.y * B.x;
}

bool tagh(point A, point B, point C, point D){
	LD alp = zcross(C - A, D - C) / zcross(B - A, D - C);
	swap(A, C), swap(B, D);
	LD bet = zcross(C - A, D - C) / zcross(B - A, D - C);
	return alp >= 0. and alp <= 1. and bet >= 0. and bet <= 1.;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y, xx, yy;
	cin >> x >> y >> xx >> yy;
	x -= xx;
	y -= yy;
	if(x < 0 or (x == 0 and y < 0)) x = -x, y = -y;
	if(y >= 0){
		if(x * 2 == y or y * 2 == x)
			return cout << 1+min(x, y) << endl, 0;
		vec[0] = point(+sq3/6., -.50);
		vec[1] = point(+.50, +.00);
		vec[2] = point(+vec[0].x, +.50);
		vec[3] = point(0, 0) - vec[0];
		xx = yy = 0;
		point A(0., 0.),
			  B = Conv(point(LD(x), LD(y)));
		point cur(0., 0.);
		int ans = 1;
		while(x != xx or y != yy){
			for(int i = 0; i < 4; i++)
				P[i] = cur + vec[i];
			if(tagh(A, B, P[0], P[1]))
				xx++;
			else if(tagh(A, B, P[1], P[2]))
				xx++, yy++;
			else if(tagh(A, B, P[2], P[3]))
				yy++;
			cur = Conv(point(xx, yy));
			ans++;
			if(ans >= 100000) assert(0);
		}
		cout << ans << endl;
		return 0;
	}
	else{
		if(x == -y)
			return cout << 1+x << endl, 0;
		//return cout << x - y + 1 << endl, 0;
	}
	assert(0);
	return 0;
}
