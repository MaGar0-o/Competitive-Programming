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

const int maxn = 2e5 + 85 - 69;
int con[maxn],
	alt[maxn],
	par[maxn],
	len[maxn],
	dp[maxn],
	a[maxn], n;
stringstream ss;

int LEN(int val){
	int ret = 1;
	while(val)
		ret++, val /= 10;
	return ret;
}

void add_alt(int a, int b){
	if(a == b)
		ss << a << ',';
	else
		ss << a << (a&1 ? '#' : '%') << b << ',';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		len[i] = LEN(a[i]);
	a[0] = -6;
	for(int i = 1; i <= n; i++)
		con[i] = (a[i] == a[i - 1] + 1) ? con[i - 1] : i;
	for(int i = 1; i <= n; i++)
		alt[i] = (a[i] == a[i - 1] + 2) ? alt[i - 1] : i;
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1] + len[i];
		if(dp[con[i] - 1] + len[i] + len[con[i]] < dp[i]){
			dp[i] = dp[con[i] - 1] + len[i] + len[con[i]]; 
			par[i] = 1;
		}
		if(con[i] != i){
			if((con[i] & 1) == (i & 1)){
				int cur = dp[alt[con[i]] - 1] + len[alt[con[i]]] + len[i] + len[i - 1] + (con[i] + 1 != i - 1 ? len[con[i] + 1] : 0);
				if(cur < dp[i])
					dp[i] = cur, par[i] = 2;
			}
			else{
				int cur = dp[alt[con[i]] - 1] + len[i] + (con[i] != i - 1 ? len[con[i] + 1] : 0) + len[i - 1] + (alt[con[i]] != i - 1 ? len[alt[con[i]]] : 0);
				if(cur < dp[i])
					dp[i] = cur, par[i] = 3;
			}
		}
		else if(alt[i] < i and dp[alt[i] - 1] + len[alt[i]] + len[i] < dp[i])
			dp[i] = dp[alt[i] - 1] + len[alt[i]] + len[i], par[i] = 4;
	}
	cout << dp[n] - 1 << endl;
	int id = n;
	while(id){
		if(par[id] == 0)
			ss << a[id] << ',', id--;
		else if(par[id] == 1)
			ss << a[con[id]] << '-' << a[id] << ',', id = con[id] - 1;
		else if(par[id] == 2){
			add_alt(a[alt[con[id]]], a[id]);
			add_alt(a[con[id] + 1], a[id - 1]);
			id = alt[con[id]] - 1;
		}
		else{
			add_alt(a[alt[con[id]]], a[id - 1]);
			add_alt(a[con[id] + 1], a[id]);
			id = alt[con[id]] - 1;
		}
	}
	for(int i = 0; i <= n; i++)
		cout << setw(4) << a[i] << ' ';
	cout << endl;
	for(int i = 0; i <= n; i++)
		cout << setw(4) << dp[i] << ' ';
	cout << endl;
	cout << ss.str().substr(0, sz(ss.str()) - 1) << '\n';
	return 0;
}
