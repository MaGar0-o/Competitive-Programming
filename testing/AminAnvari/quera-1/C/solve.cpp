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
vector<int> all,
	vec[maxn];
int a[maxn],
	nxt[maxn],
	n;
stack<int> stc;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	stc.push(n);
	for(int i = n - 1; i >= 0; i--){
		while(stc.top() != n and a[stc.top()] >= a[i])
			stc.pop();
		nxt[i] = stc.top();
		stc.push(i);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++)
		vec[a[i] = lower_bound(all(all), a[i]) - all.begin()].PB(i);
	int ans = 0;
	for(int i = 0; i < sz(all); i++){
		int ptr = 0;
		for(int j = 0; j < sz(vec[i]); j++){
			while(ptr < sz(vec[i]) and vec[i][ptr] < nxt[vec[i][j]])
				ptr++;
			smax(ans, ptr - j);
		}
	}
	cout << ans << '\n';
	return 0;
}
