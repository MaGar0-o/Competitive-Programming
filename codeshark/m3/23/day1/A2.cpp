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

const LL Mod = 10859;
const LL n = Mod + 3;

LL f(LL x){
	LL ret = 1;
	while(x){
		if(x & 1)
			ret = (ret * 3) % Mod;
		else
			ret = (ret * 2) % Mod;
		x>>=1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL sum = 0;
	for(int i = 1; i < n; i++){
		if(i % Mod == 0)
			cout << i / Mod << endl;
		sum = (sum + f(i)) % Mod;
	}
	LL sum2 = (n * (n - 1) / 2) % Mod;
	cout << (sum * sum2) % Mod << endl;
	return 0;
}
