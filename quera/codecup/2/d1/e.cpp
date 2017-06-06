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

const int maxn = 1e5 + 85 - 69,
	  maxsq = 320;
LL sum[maxsq][maxn<<1],
   a[maxn];
int n, q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int j = 1; j < maxsq; j++)
		for(int i = 0; i < n; i++)
			sum[j][i + j] = sum[j][i] + a[i];
	while(q--){
		int le, ri, k;
		cin >> le >> ri >> k;
		le--, ri--;
		if(k < maxsq)
			cout << sum[k][ri + k] - sum[k][le] << '\n';
		else{
			LL ans = 0;
			for(int i = le; i <= ri; i+=k)
				ans += a[i];
			cout << ans << '\n';
		}
	}

	return 0;
}
