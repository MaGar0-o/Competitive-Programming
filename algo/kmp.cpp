//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())
#define next nxt

const int maxn = 1e5 + 10;
int next[maxn];
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	int match = 0;
	for(int i = 2; i <= sz(t); i++){
		while(match and t[match] != t[i - 1])
			match = next[match];
		match += t[match] == t[i - 1];
		next[i] = match;
	}
	match = 0;
	int cur = 0;
	for(int i = 0; i < sz(s); i++){
		while(match and s[i] != t[match])
			match = next[match];
		match += s[i] == t[match];
		if(match == sz(t))
			cur++, match = next[match];
	}
	cout << cur << endl;
	return 0;
}
