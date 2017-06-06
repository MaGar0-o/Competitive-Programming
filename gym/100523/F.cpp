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
int d[maxn],
	l[maxn],
	n, k;
multiset<int> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> d[i];
	for(int i = 0; i < k; i++)
		cin >> l[i], s.insert(l[i]);
	sort(d, d + n, greater<int>());
	for(int i = 0; i < n; i++){
		int sup = 5 * d[i],
			soc = 2 * d[i],
			shi = 3 * d[i];
		auto it = s.lower_bound(sup);
		if(it != s.end()){
			s.erase(it);
			ans++;
		}
		else{
			it = s.lower_bound(shi);
			if(it == s.end()){
				cout << "NIE\n";
				return 0;
			}
			s.erase(it);
			it = s.lower_bound(soc);
			if(it == s.end()){
				cout << "NIE\n";
				return 0;
			}
			s.erase(it);
			ans += 2;
		}
	}
	cout << ans << '\n';
	return 0;
}
