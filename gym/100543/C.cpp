//sobskdrbhvk
//remember the flying, the bird dies ):(
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

int solve(){
	int n;
	cin >> n, n<<=1;
	bool can = false;
	for(int i = 2; i*i <= n; i++) if(n % i == 0){
		int len = i;
		int x = n / i;
		if((len + x - 1) & 1)
			continue;
		int r = (len + x - 1) / 2;
		cout << n/2 << " = ";
		for(int i = 1; i <= len; i++)
			cout << r - len + i << (i == len ? "\n" : " + ");
		can = true;
		break;
	}
	if(!can)
		cout << "IMPOSSIBLE\n";
	return 0;
}

int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
