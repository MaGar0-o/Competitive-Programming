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

LD dot(point A, point B){
	return A.x * B.x + A.y * B.y;
}

point tasvir(point A, point B, point C){
	LD d = dot(C - A, B - A);
	return (B - A) * d / dot(B - A, B - A) + A;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> R;
	for(int i = 0; i < n; i++){
		int xx, yy;
		cin >> xx >> yy;
		p[i] = point(xx, yy);
	}
	LD ans = 0;
	point O(0, 0);
	for(int i = 0; i < n; i++){
		point cur = p[i],
			prv = p[(i + 1) % n];
		point P = tasvir(cur, prv, O);
		if(ABS(R - leng(P)) <= EPS){

		}
	}
	return 0;
}
