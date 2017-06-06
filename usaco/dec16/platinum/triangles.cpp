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
#define x real()
#define y imag()

const int maxn = 300;
bitset<maxn> a[maxn][maxn],
	tmp;
int ans[maxn],
	n;
point p[maxn];

LL zcross(point A, point B){
	return A.x * B.y - A.y * B.x;
}

int main(){
	ifstream cin("triangles.in");
	ofstream cout("triangles.out");
	cin >> n;
	for(int i = 0; i < n; i++){
		LL fi, se;
		cin >> fi >> se;
		p[i] = point(fi, se);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i^j)
				for(int k = 0; k < n; k++)
					a[i][j][k] = zcross(p[j] - p[i], p[k] - p[i]) < 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			for(int k = j + 1; k < n; k++)
				if(a[i][j][k]) ans[(a[i][j] & a[j][k] & a[k][i]).count()]++;
				else ans[(a[i][k] & a[k][j] & a[j][i]).count()]++;
	for(int i = 0; i <= n - 3; i++)
		cout << ans[i] << '\n';
	return 0;
}
