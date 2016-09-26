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

const LL Mod = 14947;

struct matrix{
	int n, m;
	LL a[4][4];
	matrix(int x = 4, int y = 4, int val = 1){
		n = x;
		m = y;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				a[i][j] = (i==j) * val;
		return;
	}
	LL* operator[](int i){return a[i];}
}D(4,4,0), bas(4, 1);

matrix operator*(matrix &A, matrix &B){
	matrix ret(A.n, B.m, 0);
	for(int i = 0; i < A.n; i++)
		for(int j = 0; j < B.m; j++){
			for(int k = 0; k < A.m; k++)
				ret[i][j] += A[i][k] * B[k][j];
			ret[i][j] %= Mod;
		}
	return ret;
}

matrix Pow(matrix &A, LL x){
	matrix ret(A.n, A.m),
		   an = A;
	while(x){
		if(x & 1) ret = ret * an;
		an = an * an;
		x>>=1;
	}
	return ret;
}

LL f(LL i){
	matrix A = Pow(D, i);
	matrix B = A * bas;
	return B[1][0];
}

LL g(LL i){
	matrix A = Pow(D, i);
	matrix B = A * bas;
	return B[3][0];
}

LL calc_f(LL i){
	return (2*f(i-1) + 2*g(i - 3)) % Mod;
}

LL Pow(LL x, LL y){
	LL ret = 1, an = x;
	while(y){
		if(y&1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y>>=1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 4; i++)
		bas[i][0] = (i != 3);
	D[0][0] = D[0][3] = D[1][0] = D[2][1] = D[2][2] = D[3][2] = 1;
	matrix an = D;// * D;//Pow(D, 2);
	for(int i = 0; i < 4; i++, cout << endl)
		for(int j = 0; j < 4; j++)
			cout << an[i][j] << ' ';
	for(int i = 0; i < 10; i++)
		cout << f(i) << " \n"[i == 9];
	for(int i = 0; i < 10; i++)
		cout << g(i) << " \n"[i == 9];
	for(int i = 3; i < 10; i++)
		cout << calc_f(i) << " \n"[i == 9];
	LL ans = 0;
	LL x = 1000 * 1000 * 1000 + 7;
	ans = calc_f(x);
	x %= Mod;
	cout << ((ans - 2) * Pow(x, Mod - 2) + 2) % Mod << endl;
	return 0;
}
