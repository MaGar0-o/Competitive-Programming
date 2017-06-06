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

const int maxn = 1e6 + 85 - 69;
set<int> s;
int p[maxn],
	n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x, x--;
		p[x] = i;
	}
	for(int i = 1; i < n; i++)if (p[i]){
		if(s.lower_bound(p[i]) != s.end())
			s.erase(s.lower_bound(p[i]));
		s.insert(p[i]);
	}
	cout << 2 * (n - 1) - sz(s) << endl;
	return 0;
}
