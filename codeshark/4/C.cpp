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

const LL Mod = 77543;
const int maxn = 2e6;
LL P[maxn];

LL f(LL x){
	if(x <= 2)
		return 1;
	return (P[x / 2] * f((x + 1) / 2) + f(x / 2)) % Mod;
}

int main(){
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * 2) % Mod;
	cout << (f(3) + f(4)) % Mod << endl
		<< (f(10) + f(7)) % Mod << endl
		<< (f(19) + f(20)) % Mod << endl
		<< (f(59) + f(56)) % Mod << endl
		<< (f(1000000) + f(1000000 - 9)) % Mod << endl;
		//<< (f(1000000000LL * 1000000000LL - 2) + f(1000000000LL * 1000000000LL - 9)) % Mod << endl;
	return 0;
}
