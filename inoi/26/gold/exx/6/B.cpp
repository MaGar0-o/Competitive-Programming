//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
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
#define x real()
#define y imag()
#define fabs ABS

const int maxn = 200;
point p[maxn];
int n;

LD zcross(point A, point B){
	return A.x * B.y - A.y * B.x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	cout.precision(6);
	while(cin >> n and n){
		cnt++;
		for(int i = 0; i < n; i++){
			int xx, yy;
			cin >> xx >> yy;
			p[i] = point(xx, yy);
		}
		LD su = zcross(p[n - 1], p[0]) / 2.;
		point ans = (p[0] + p[n - 1]) / 3. * su;
		for(int i = 0; i+1 < n; i++){
			LD ns = zcross(p[i], p[i+1]) / 2.;
			point P = (p[i] + p[i + 1]) / 3. * ns;
			ans = (ans + P);
			su += ns;
		}
		cout << "Stage #" << cnt << ": ";
		cout << fixed << ans.x / su << ' ' << ans.y / su << '\n';
	}
	return 0;
}
