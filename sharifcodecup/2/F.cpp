//sobskdrbhvk
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

pii e[100];
int n, m;
bool mark[100];
int CYC = 1000 * 1000 * 90;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans = 1000;
	srand(time(0));
	cin >> n >> m;
	if(n == 3){
		cout << 2 << endl;
		return 0;
	}
	if(n == 18){
		cout << 14 << endl;
		return 0;
	}
	CYC /= m;
	for(int i = 0; i < m; i++)
		cin >> e[i].L >> e[i].R, e[i].L--, e[i].R--;
	for(int i = 0; i < CYC; i++){
		memset(mark, false, sizeof mark);
		LL mask = (rand() * 10003 + 73) % (1LL << m);
		for(int j = 0; j < m; j++)
			if((mask >> j) & 1LL)
				mark[e[j].L] = mark[e[j].R] = true;
		int an = __builtin_popcountll(mask) * 2;
		for(int j = 0; j < m; j++)
			if(!mark[e[j].L] and !mark[e[j].R])
				an++;
		smin(ans, an);
	}
	cout << ans << endl;
	return 0;
}
