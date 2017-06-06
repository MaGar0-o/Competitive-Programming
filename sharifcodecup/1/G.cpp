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

const int maxn = 100,
	  maxc = 256;
char a[maxn][maxn];
int rcnt[maxn][maxc],
	ccnt[maxn][maxc];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			a[i][j] = c;
			rcnt[i][c]++;
			ccnt[j][c]++;
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(rcnt[i][a[i][j]] == 1 and ccnt[j][a[i][j]] == 1)
				cout << a[i][j];
	return 0;
}
