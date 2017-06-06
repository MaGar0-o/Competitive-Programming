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

const int maxn = 4000 + 85 - 69;
vector<LL> xall,
	yall;
bool mark[maxn][maxn],
	 can[maxn][maxn];
LL x[maxn],
   y[maxn],
   xx[maxn],
   yy[maxn];
set<int> cans[maxn],
	maks[maxn];
LL n, m;
int q;

int idof(LL val, vector<LL> &all){
	return lower_bound(all(all), val) - all.begin();
}

void dfs(int x, int y){
	if(x >= sz(xall) - 1 or y >= sz(yall) - 1 or can[x][y]) return;
	if(!mark[x][y]){
		cans[x].insert(y);
		return;
	}
	can[x][y] = true;
	cans[x].erase(y);
	dfs(x + 1, y);
	dfs(x, y + 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < q; i++){
		cin >> x[i] >> y[i] >> xx[i] >> yy[i];
		xall.PB(x[i]);
		xall.PB(++xx[i]);
		yall.PB(y[i]);
		yall.PB(++yy[i]);
	}
	xall.PB(1);
	xall.PB(2);
	yall.PB(1);
	yall.PB(2);
	xall.PB(n);
	xall.PB(n + 1);
	yall.PB(m);
	yall.PB(m + 1);
	sort(all(xall));
	sort(all(yall));
	xall.resize(unique(all(xall)) - xall.begin());
	yall.resize(unique(all(yall)) - yall.begin());
	for(int i = 0; i < sz(xall); i++)
		for(int j = 0; j < sz(yall); j++)
			maks[i].insert(j);
	cans[0].insert(0);
	for(int i = 0; i < q; i++){
		x[i] = idof(x[i], xall);
		y[i] = idof(y[i], yall);
		xx[i] = idof(xx[i], xall);
		yy[i] = idof(yy[i], yall);
		for(int r = x[i]; r < xx[i]; r++){
			auto it = maks[r].lower_bound(y[i]);
			while((*it) < yy[i]){
				int c = *it;
				mark[r][c] = true;
				maks[r].erase(c);
				it++;
			}
		}
		for(int r = x[i]; r < xx[i]; r++){
			auto it = cans[r].lower_bound(y[i]);
			while((*it) < yy[i]){
				int c = *it;
				dfs(r, c);
				it++;
			}
		}
		if(can[sz(xall) - 2][sz(yall) - 2]) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
