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

const int maxn = 1e5 + 85 - 69;
const LL Inf = 1e18;
LL mn[maxn],
	a[maxn],
	n, E, T;
LL dp[maxn];
deque<int> dq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> E >> T;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	a[n + 1] = E;
	int ptr = 1;
	dq.push_front(0);
	for(int i = 1; i <= n; i++){
		while(2 * (a[i] - a[ptr]) > T) ptr++;
		while(sz(dq) and dq.back() + 1 < ptr) dq.pop_back();
		dp[i] = Inf;
		if(sz(dq))
			dp[i] = dp[dq.back()] + (a[i] - a[dq.back()]) + T;
		if(ptr >= 2)
			smin(dp[i], dp[mn[ptr - 2]] + 2 * (a[i] - a[mn[ptr - 2] + 1]) + a[i] - a[mn[ptr - 2]]);
		while(sz(dq) and dp[i] - a[i] <= dp[dq.front()] - a[dq.front()])
			dq.pop_front();
		dq.push_front(i);
		mn[i] = mn[i - 1];
		if(dp[i] - 2 * a[i + 1] - a[i] < dp[mn[i]] - 2 * a[mn[i] + 1] - a[mn[i]])
			mn[i] = i;
	}
	cout << dp[n] + E - a[n] << endl;
	return 0;
}
