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

const int maxn = 1000;
int a[maxn], ans[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], a[i]++;
	memset(ans, -1, sizeof ans);
	for(int i = 0; i < n; i++){
		int cnt = 0, j = 0;
		for(j; cnt < a[i]; j++) cnt += ans[j] == -1;
		ans[j - 1] = i + 1;
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << ",\n"[i == n - 1];
	return 0;
}
