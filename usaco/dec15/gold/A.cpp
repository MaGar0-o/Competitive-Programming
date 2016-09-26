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

const int maxn = 1e5 + 85 - 69;
int a[maxn],
	b[maxn],
	cnt1[maxn],
	cnt2[maxn],
	dp[maxn],
	n, ans;
bool mark[maxn];
vector<int> vec;

int main(){
	ifstream cin("cardgame.in");
	ofstream cout("cardgame.out");
	cin >> n;
	n>>=1;
	for(int i = 0; i < n; i++)
		cin >> a[i], mark[--a[i]] = true;
	for(int i = 0; i < n; i++)
		cin >> b[i], mark[--b[i]] = true;
	sort(a, a + n);
	sort(b, b + n);
	n *= 2;
	for(int i = 0; i < n * 2; i++)
		if(!mark[i])
			vec.PB(i);
	int ptr = n / 2;
	int mn = 2e6;
	for(int i = n - 1; i >= 0; i--){
		while(ptr and vec[i] < a[ptr - 1]) ptr--;
		cnt1[i] = ptr;
		smin(mn, cnt1[i]);
		mn--;
		if(mn < 0)
			dp[i] = dp[i + 1];
		else
			dp[i] = n - i;
	}
	int ans = dp[0];
	ptr = n / 2;
	mn = 2e6;
	for(int i = 0; i < n; i++){
		while(ptr and vec[i] > b[n/2 - ptr]) ptr--;
		cnt2[i] = ptr;
		smin(mn, cnt2[i]);
		mn--;
		if(mn >= 0)
			smax(ans, i + 1 + dp[i + 1]);
		else
			smax(ans, dp[i + 1]);
	}
	cout << ans << endl;
	return 0;
}
