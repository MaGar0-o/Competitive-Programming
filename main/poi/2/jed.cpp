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

const int maxn = 1e6;
int par[maxn];
int P[100 + 10];
vector<int> vec;
int n;

void print(void){
	int ptr = par[0],
		val = 0;
	do{
		cout << 1;
		val = ((val - P[ptr]) % n + n) % n;
		ptr--;
		while(ptr > par[val])
			ptr--, cout << 0;
	}while(val);
	while(ptr >= 0) cout << 0, ptr--;
	cout << '\n';
	return;
}

bool move(int i, int val){
	for(int ii = sz(vec) - 1; ii >= 0; ii--){
		int x = vec[ii];
		int val2 = (val + x) % n;
		if(!~par[val2])
			par[val2] = i, vec.PB(val2);
		if(!val2)
			return print(), false;
	}
	return true;
}

void solve(void){
	vec.clear();
	memset(par, -1, sizeof par);
	cin >> n;
	for(int i = 1; i < 100; i++)
		P[i] = (P[i - 1] * 10) % n;
	vec.PB(0);
	int val = 1;
	for(int i = 0; move(i, val); i++)
		val = (val * 10) % n;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	vec.reserve(1<<20);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
