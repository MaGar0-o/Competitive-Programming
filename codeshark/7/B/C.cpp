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
int pri[8] = {2, 3, 5, 7, 11, 13, 17, 19},
	func[1 << 8];
vector<int> all, emp;
map<vector<int>, LL> dp, su;

int f(int n, int p){
	return n == 0 ? 0 : n/p + f(n/p, p);
}

int f2(int x, int d){
	int ret = 0;
	while(x % d == 0) ret++, x/=d;
	return ret;
}

LL calc(void){
	if(su[all])
		return su[all];
	for(int i = 0; i < 8; i++)
		if(all[i] < 0)
			return 0;
	if(all == emp)
		return su[all] = dp[all] = 1;
	LL val = 0;
	for(int mask = 1; mask < (1 << 8); mask++){
		for(int i = 0; i < 8; i++)
			if((mask >> i) & 1)
				all[i]--;
		val += calc() * func[mask];
		for(int i = 0; i < 8; i++)
			if((mask >> i) & 1)
				all[i]++;
	}
	val %= Mod;
	dp[all] = val;
	return su[all] = (2 * val) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	all.resize(8);
	emp.resize(8);
	func[0] = -1;
	for(int mask = 1; mask < (1 << 8); mask++)
		func[mask] = -func[mask - (mask&-mask)];
	for(int i = 0; i < 8; i++)
		all[i] = f(n, pri[i]);
	calc();
	LL ret = 0;
	vector<int> an(8);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 8; j++)
			an[j] += f2(i, pri[j]);
		ret = (ret + dp[an]) % Mod;
	}
	cout << (ret+Mod)%Mod << endl;
	return 0;
}
