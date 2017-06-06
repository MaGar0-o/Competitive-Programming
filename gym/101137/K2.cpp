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
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for(int i = 0; i < m; i++)
		cin >> frm[i] >> too[i] >> wei[i], frm[i]--, too[i]--;
	iota(ord, ord + m, 0);
	sort(ord, ord + m, cmp);
	for(int i = 0; i < m; i++){
		int id = ord[i];
		if(merge(frm[id], too[id])){
			adj[frm[id]].PB(id);
			adj[too[id]].PB(id);
		}
	}
	
	return 0;
}
