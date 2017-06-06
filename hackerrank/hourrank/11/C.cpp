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

const int maxn = 1e6 + 85 - 69;
const LL Mod = 1e9 + 7;
LL P[maxn],
   ps[maxn],
   ans, n;
string s;

LL func(int dig){
	return ps[dig];
}

void go_on(int ptr = 0){
	if(ptr == sz(s)){
		ans++;
		return;
	}
	for(int i = 0; i < min(5, s[ptr] - '0'); i++)
		ans += func(sz(s) - ptr - 1);
	ans %= Mod;
	if(s[ptr] >= '5')
		return;
	go_on(ptr + 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = ps[0] = 1;
	for(int i = 1; i < maxn; i++)
		ps[i] = (ps[i - 1] + (P[i] = (P[i - 1] * 5) % Mod)) % Mod;
	cin >> s >> n;
	LL num = 0;
	for(auto c : s)
		num = (num * 10 + c - '0') % Mod;
	go_on();
	ans = (ans + Mod - 1) % Mod;
	ans = (num - ans + Mod * 10) % Mod;
	cout << ans << endl;
	return 0;
}
