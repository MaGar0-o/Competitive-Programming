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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s[2];
	cin >> s[0] >> s[1];
	int ans = 0,
		cur = 0,
		nxt = 1,
		p1 = 0,
		p2 = 0;
	while(p1 < sz(s[cur]) and p2 < sz(s[nxt])){
		if(s[cur][p1] == 'R'){
			if(s[nxt][p2] != 'L')
				p2++;
			p1++, ans++;
		}
		else if(s[cur][p1] == 'F'){
			if(s[nxt][p2] != 'L')
				p2++;
			p1++, ans++;
		}
		else if(s[cur][p1] == 'L' and s[nxt][p2] == 'L')
			ans++, p1++, p2++;
		else
			swap(cur, nxt), swap(p1, p2);
	}
	ans += sz(s[cur]) + sz(s[nxt]) - (p1 + p2);
	cout << ans << endl;
	return 0;
}
