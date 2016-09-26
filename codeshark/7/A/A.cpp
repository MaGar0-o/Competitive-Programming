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

const int maxn = 1e5;
LL f[maxn][2];
const LL Mod= 14947;

LL Pow(LL x, LL y){
	LL ret = 1, an = x;
	while(y){
		if(y & 1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y>>=1;
	}
	return ret;
}

LL Div(LL x, LL y){
	return (x * Pow(y, Mod - 2)) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	f[0][0] = 1;
	f[1][0] = f[1][1] = 1;
	for(int i = 2; i < maxn; i++)
		for(int j = 0; j < 2; j++)
			f[i][j] = (f[i - 1][j] + f[i - 2][1 - j]) % Mod;
	int n;
	cin >> n;
	LL val = 0;
	cout << "subtask1: " << (val = (2*f[n - 1][0] + 2*f[n - 3][1]) % Mod) << endl;
	cout << "subtask2: " << Div(val-2, n)+2 << endl;
	LL ret = 0;
	for(int i = 3; i <= 100000; i++)
		ret = (ret + 2 * (f[i - 1][0] + f[i - 3][1])) % Mod;
	cout << "subtask3: " << ret << endl;
	return 0;
}
