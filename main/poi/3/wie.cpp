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

const int maxn = 3000 + 10;
int x[maxn],
	y[maxn],
	a[maxn],
	b[maxn],
	c[maxn],
	d[maxn],
	ord[maxn],
	n;
set<int> s;

bool cmp(int i, int j){
	return b[i] < b[j];
}

void solve(int *ans){
	sort(ord, ord + n, cmp);
	for(int i = 0; i < n; i++)
		s.insert(i);
	for(int i = 0; i < n; i++){
		int id = ord[i];
		set<int>::iterator it = s.lower_bound(a[id]);
		if(it == s.end() or *it >= b[id]){
			cout << "NIE\n";
			exit(0);
		}
		ans[id] = *it;
		s.erase(it);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i], a[i]--, b[i]--;
	for(int i = 0; i < n; i++)
		ord[i] = i, swap(b[i], c[i]);
	solve(x);
	for(int i = 0; i < n; i++)
		swap(a[i], c[i]), swap(b[i], d[i]);
	solve(y);
	for(int i = 0; i < n; i++)
		cout << x[i]+1 << ' ' << 1+y[i] << '\n';
	return 0;
}
