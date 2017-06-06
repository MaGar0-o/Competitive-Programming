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
#define next nxt

const int maxn = 1e6 + 10;
LL a, c, k, m, n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vec.reserve(maxn);
	cin >> a >> c >> k >> m >> n;
	for(int i = 0; i < m; i++)
		func[i] = ((i * a + b) / k) % m;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		t.PB(c - '0');
	}
	reverse(all(t));
	int match = 0;
	for(int i = 2; i <= sz(t); i++){
		while(match and t[match] != t[i - 1])
			match = next[match];
		match += t[i - 1] == t[match];
		next[i] = match;
	}
	for(int i = 0; i < m; i++) if(!cnt[i]){
		LL z = i;
		match = 0;
		vec.clear();
		while(1){
			z = ((z * a + c) / k) % m;
			bool val = z >= m / 2;
			cout << z << '\t' << val << endl;
			cnt[val]++;
			if(cnt[val] >= 3) break;
			while(match and val ^ t[match])
				match = next[match];
			match += val^t[match]^1;
			if(match == sz(t)){
				can[vec[sz(vec) - sz(t) - 1]] = true;
				match = next[match];
			}
		}
		cout << endl;
	}
	match = 0;
	for(int i = 1; i < sz(s); i++){
		while(match and s[i] != t[match])
			match = next[match];
		match += s[i] == t[match];
		if(match == sz(t)){
			can[vec[i - sz(t)]] = true;
			cout << vec[i - sz(t)] << endl;
			match = next[match];
		}
	}
	int ans = 0;
	for(int i = 0; i < m; i++)
		ans += can[i];
	cout << ans << '\n';
	return 0;
}
