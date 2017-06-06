//sobskdrbhvk
//remember the flight, the bird dies ):(
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

const int maxn = 1e5 + 85 - 69;
LL dp[maxn],
   a[maxn],
   b[maxn];
int n;
int ord[5];
bool can;

LL dist(LL x, LL y){
	if(x == y) can = false;
	return ((x - y)>>63) ? y - x : x - y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int l = 1; l <= 3 and i - l + 1 >= 0; l++){
			for(int j = 0; j < l; j++)
				ord[j] = i - j;
			do{
				can = true;
				LL cur = 0;
				for(int j = 0; j < l; j++)
					cur += dist(a[i - j], b[ord[j]]);
				if(can) smin(dp[i + 1], cur + dp[i - l + 1]);
			}while(prev_permutation(ord, ord + l));
		}
	}
	cout << dp[n] << endl;
	return 0;
}
