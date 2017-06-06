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

const int maxn = 750 + 10;
bitset<maxn> a[maxn];
bool b[maxn * 2];
int pos[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(pos, -1, sizeof pos);
	cin >> n;
	for(int i = 0; i < n+n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			a[i][j] = b[i + (n - 1) - j];
		a[i][n] = b[i + n];
	}
	int cur = 0;
	for(int j = 0; j < n; j++){
		for(int i = cur; i < n; i++)
			if(a[i][j]){
				swap(a[i], a[cur]);
				break;
			}
		if(!a[cur][j])
			continue;
		for(int i = 0; i < n; i++)
			if(i != cur and a[i][j])
				a[i] ^= a[cur];
		pos[j] = cur++;
	}
	for(int i = cur; i < n; i++)
		if(a[i][n]){
			cout << -1 << endl;
			return 0;
		}
	for(int i = 0; i < n; i++)
		if(~pos[i])
			cout << a[pos[i]][n] << ' ';
		else
			cout << 0 << ' ';
	cout << '\n';
	return 0;
}
