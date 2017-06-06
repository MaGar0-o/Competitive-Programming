//sobskdrbhvk
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

const int maxn = 200;
const LL Inf = 2e18;
int n, m, k;

struct matrix{
	LL a[maxn][maxn];
	matrix(){
		for(int i = 0; i < maxn; i++)
			for(int j = 0; j < maxn; j++)
				a[i][j] = Inf;
		return;
	}
	LL *operator[](int i){
		return a[i];
	}
};

matrix operator*(matrix &A, matrix &B){
	matrix ret;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				smin(ret[i][j], A[i][k] + B[k][j]);
	return ret;
}

matrix operator~(matrix &A){
	matrix ret = A;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				smin(ret[i][j], A[i][k] + A[k][j]);
	return ret;
}

matrix Pow(matrix &A, LL b){
	matrix ret,
		   an = A;
	for(int i = 0; i < n; i++)
		ret[i][i] = 0;
	while(b){
		if(b & 1)
			ret = ret * an;
		an = an * an;
		b >>= 1;
	}
	return ret;
}

matrix Pow2(matrix &A, int b){
	matrix ret = A;
	for(int i = 0; i < b; i++)
		ret = ~ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	matrix A;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		A[fi][se] = th;
	}
	matrix B = Pow(A, k);
	matrix C = Pow2(B, 32);
	cout << (C[0][n - 1] == Inf ? -1 : C[0][n - 1]) << '\n';
	return 0;
}
