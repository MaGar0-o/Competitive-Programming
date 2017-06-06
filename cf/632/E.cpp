//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef float LD;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int lg = 20,
	  nn = 1<<20;
const LD PI = 3.1415926535;
int rev[nn];
LD fnc[2][nn+1][2];

struct point{
	LD x, y;
	point(LD xx = 0, LD yy = 0){
		x = xx;
		y = yy;
	}
	void operator*=(point &A){
		LD nx = x * A.x - y * A.y,
		   ny = x * A.y + y * A.x;
		x = nx, y = ny;
	}
};

point operator*(point &A, point &B){
	return point(A.x * B.x - A.y * B.y, A.x * B.y + A.y * B.x);
}

point operator+(point A, point B){
	return point(A.x + B.x, A.y + B.y);
}

point operator-(point &A, point B){
	return point(A.x - B.x, A.y - B.y);
}

point operator/(point &A, LD x){
	return point(A.x / x, A.y / x);
}

void fft(point *a, bool inv = false){
	for(int i = 0; i < nn; i++)
		if(rev[i] < i)
			swap(a[i], a[rev[i]]);
	for(int len = 2; len <= nn; len <<= 1){
		point wn(fnc[inv][len][0], fnc[inv][len][1]);
		for(int i = 0; i < nn; i += len){
			point w(1., 0.);
			for(int j = 0; j < len / 2; j++){
				auto t1 = a[i + j] + w * a[i + j + len / 2];
				auto t2 = a[i + j] - w * a[i + j + len / 2];
				a[i + j] = t1;
				a[i + j + len / 2] = t2;
				w *= wn;
			}
		}
	}
	if(inv) for(int i = 0; i < nn; i++) a[i] = a[i] / nn;
}

point an[nn],
	  ans[nn];

int main(){
	for(int len = 2; len <= nn; len <<= 1){
		fnc[0][len][0] = cos(2 * PI / len);
		fnc[0][len][1] = sin(2 * PI / len);
		fnc[1][len][0] = +fnc[0][len][0];
		fnc[1][len][1] = -fnc[0][len][1];
	}
	for(int i = 0; i < nn; i++)
		for(int j = 0; j <= lg; j++)
			if((i>>j)&1)
				rev[i] += 1 << (lg - j - 1);
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		int xx;
		scanf("%d", &xx);
		an[xx] = 1;
	}
	
	ans[0] = 1;
	fft(ans);
	fft(an);
	while(k){
		if(k&1) for(int i = 0; i < nn; i++) ans[i] *= an[i];
		for(int i = 0; i < nn; i++) an[i] *= an[i];
		k >>= 1;
	}
	fft(ans, true);
	for(int i = 0; i < nn; i++)
		if(ans[i].x > .5)
			printf("%d ", i);
	printf("\n");
	return 0;
}
