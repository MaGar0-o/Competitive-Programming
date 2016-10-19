//sobskdrbhvk
//remember the flying, the bird dies :-
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
vector<int> adj[26];
string s, t, ans;
int n;

void dfs(int u){
	while(sz(adj[u])){
		int e = adj[u].back();
		adj[u].pop_back();
		dfs(t[e] - 'a');
	}
	ans += char('a' + u);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	n--;
	t = s;
	sort(all(t));
	for(int i = 0; i < sz(s); i++)
		adj[s[i]-'a'].PB(i);
	for(int i = 0; i < 26; i++)
		sort(all(adj[i]), greater<int>());
	dfs(t[0] - 'a');
	reverse(all(ans));
	ans.pop_back();
	cout << ans << '\n';
	return 0;
}
