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

const int maxn = 1e6 + 10;
map<int, int> mp;
LL P[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	LL p;
	cin >> s >> p;
	if(p == 2){
		LL ans = 0;
		for(int i = 0; i < sz(s); i++)
			if(s[i] & 1 ^ 1)
				ans += i + 1;
		cout << ans << '\n';
		return 0;
	}
	if(p == 5){
		LL ans = 0;
		for(int i = 0; i < sz(s); i++)
			if((s[i] - '0') % 5 == 0)
				ans += i + 1;
		cout << ans << '\n';
		return 0;
	}
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * 10) % p;
	LL val = 0;
	mp[val] = 1;
	LL ans = 0;
	for(int i = sz(s) - 1; i >= 0; i--){
		val = (val + P[sz(s) - i - 1] * (s[i] - '0')) % p;
		ans += mp[val]++;
	}
	cout << ans << '\n';
	return 0;
}
