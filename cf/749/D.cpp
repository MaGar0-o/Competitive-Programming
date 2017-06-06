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
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		idx[i] = cnt[a[i]]++;
		vec[a[i]].PB(i);
	}
	stc.PB(-1);
	for(int i = n - 1; i >= 0; i--)
		if(idx[i] == cnt[a[i]])
			stc.PB(a[i]);
	ans[0] = n - 1;
	for(int i = 0; i < n; i++) s.insert(i);
	for(int i = 1; i < sz(stc); i++){
	}
	cin >> q;
	while(q--){
		int cnt;
		cin >> cnt;
		for(int i = 0; i < cnt; i++)
	}
	return 0;
}
