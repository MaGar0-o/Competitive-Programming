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
#define next nxt
#define last lst

const int maxn = 2e5 + 85 - 69;
int a[maxn],
	next[maxn],
	last[maxn],
	n;
stack<int> stc;

int dist(int i, int j){
	return (i<j) ? j - i : n + j - i;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], a[i + n] = a[i];
	int m = n + n;
	memset(last, -1, sizeof last);
	memset(next, -1, sizeof next);
	for(int i = 0; i < m; i++){
		while(sz(stc) and a[stc.top()] >= a[i])
			stc.pop();
		if(sz(stc)) last[i] = stc.top() % n;
		stc.push(i);
	}
	while(sz(stc))
		stc.pop();
	for(int i = m - 1; i >= 0; i--){
		while(sz(stc) and a[stc.top()] >= a[i])
			stc.pop();
		if(sz(stc)) next[i] = stc.top() % n;
		stc.push(i);
	}
	int dis = 1e6,
		ans = -1;
	for(int i = 0; i < n; i++) if(~next[i]){
		int idl = last[i + n],
			idr = next[i];
		if(dist(idl, i) + dist(i, idr) < dis){
			dis = dist(idl, i) + dist(i, idr);
			ans = i;
		}
	}
	cout << last[ans + n] + 1 << ' ' << ans + 1 << ' ' << next[ans] + 1 << '\n';
	return 0;
}
