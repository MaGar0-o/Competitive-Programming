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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	if(y[ord[0]] == y[ord[1]]){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
	return 0;
}
