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

const int n = 1e7 + 1,
	  Mod = 14947;
int f[n];
int sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	f[1] = 1;
	for(int i = 1; i < n; i++){
		sum += f[i];
		if(sum >= Mod) sum -= Mod;
		for(int j = i + i; j < n; j+=i){
			f[j] += f[i];
			if(f[j] >= Mod) f[j] -= Mod;
		}
	}
	cout << sum << endl;
	return 0;
}
