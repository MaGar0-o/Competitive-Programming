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

LL C, P, K;

LL get(LL money){
	LL cnt = money / C * 5;
	return cnt + cnt / (P - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> P >> K;
	if(P == 1){
		cout << C << endl;
		return 0;
	}
	LL lo = 0, hi = 1e18 / 5;
	while(hi - lo > 1){
		LL mid = (lo + hi) >> 1;
		if(get(mid) >= K)
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << '\n';
	return 0;
}
