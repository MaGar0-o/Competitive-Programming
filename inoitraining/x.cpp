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

const int maxn = 5000 + 10;
const LL base = 313,
	  Mod = 1e9 + 9;
set<LL> st;
string s, t;
LL P[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	cin >> s >> t;
	swap(s, t);
	{
		LL hsh = 0;
		for(int i = 0; i < sz(s); i++)
			hsh = (hsh * base + s[i]) % Mod;
		for(int i = 0; i < sz(s); i++){
			st.insert(hsh);
			hsh = (hsh * base + s[i]) % Mod;
			hsh = ((hsh - s[i] * P[sz(s)]) % Mod + Mod) % Mod;
		}
	}
	swap(s, t);
	string ss = s;
	for(int i = 0; i < sz(s); i++, rotate(s.begin(), s.begin() + 1, s.end())){
		LL hsh = 0;
		for(int j = 0; j < sz(s); j++)
			hsh = (hsh * base + (ss[j] ^ (s[j] & 1))) % Mod;;
		if(st.find(hsh) != st.end()){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
