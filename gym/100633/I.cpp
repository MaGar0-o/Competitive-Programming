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

const LL Inf = 1e17;
const int maxn = 1000 + 10;
vector<LL> c[maxn];
int num[maxn];
LL n, m;

bool cantmul(LL x, LL y){
	return x >= Inf / y + 10;
}

LL C(LL n, LL r){
	if(r == 1) return n;
	if(r == 2) return n * (n - 1) / 2;
	n -= r - 1;
	if(n < 0) return 0;
	if(n >= sz(c[r])) return Inf;
	return c[r][n];
}

bool build(LL n, int m, int mx = 10000000){
	if(m == 0)
		return n == 0;
	int id = ::m - m;
	for(num[id] = mx; num[id] >= m - 1; num[id]--)
		if(C(num[id], m) <= n)
			if(build(n - C(num[id], m), m - 1, num[id] - 1))
				return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 3; i < maxn; i++){
		c[i].PB(0);
		LL cur = 1;
		c[i].PB(cur);
		for(int j = 1; 1; j++){
			//cur = (i + j)! / i! * j!
			LL soor = (i + j);
			LL makh = (j);
			LL d = __gcd(soor, makh);
			soor /= d;
			makh /= d;
			cur /= makh;
			if(cantmul(cur, soor)) break;
			cur *= soor;
			c[i].PB(cur);
		}
	}
	cin >> n >> m;
	if(m == 1){
		cout << n << endl;
		return 0;
	}
	if(m == 2){
		LL x = (1 + sqrt(1 + 8 * n)) / 2;
		cout << x << ' ' << n - x * (x - 1) / 2 << '\n';
		return 0;
	}
	if(!build(n, m)) assert(0);
	for(int i = 0; i < m; i++)
		cout << num[i] << ' ';
	cout << '\n';
	return 0;
}
