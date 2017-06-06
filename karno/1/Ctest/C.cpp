//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())

typedef long long int LL;

const int maxn = 5e5 + 10;
const LL Mod = 1000LL * 1000 * 1000 + 7;
map<LL, int> mp;
LL a[maxn],
   dp[maxn];
int n;

//dp[i] = javaab e so'al be ezaye a[0], a[1], ..., a[i - 1]

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ptr = -1;
	LL sum = 0;
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		mp[a[i]]++;
		sum += dp[i];
		sum %= Mod;
		while(sz(mp) > 2){
			mp[a[++ptr]]--;
			sum -= dp[ptr];
			sum %= Mod;
			if(mp[a[ptr]] == 0)
				mp.erase(a[ptr]);
		}
		dp[i + 1] = (sum + Mod) % Mod;
	}
	cout << dp[n] << '\n';
	return 0;
}
