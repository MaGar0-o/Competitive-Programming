//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

#define EPS 1e-4

const int maxn = 200 + 10;
LD a[maxn][maxn];
int n, m;

bool zero(LD x){
	return abs(x) < EPS;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	int fnd = 0;
	for(int j = 0; j < m; j++){
		for(int i = fnd + 1; i < n; i++)
			if(!zero(a[i][j])){
				for(int k = 0; k < m; k++)
					swap(a[fnd][k], a[i][k]);
				break;
			}
		if(zero(a[fnd][j])) continue;
		for(int k = 0; k < m; k++)
			if(k != j)
				a[fnd][k] /= a[fnd][j];
		a[fnd][j] = 1;
		for(int i = fnd + 1; i < n; i++){
			for(int k = 0; k < m; k++)
				if(k != j)
					a[i][k] -= a[fnd][k] * a[i][j];
			a[i][j] = 0;
		}
		fnd++;
	}
	cout << fnd << '\n';
	return 0;
}
