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
int par[maxn];
string s;
stack<pair<char, int> > stc;

int root(int v){return par[v] < 0 ? v : par[v] = root(par[v]);}

void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(par[v] > par[u]) swap(v, u);
	par[v] += par[u];
	par[u] = v;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> s;
	for(int i = 0; i < sz(s); i++){
		if(s[i] <= 'Z')
			stc.push(MP(s[i], i));
		else{
			if(sz(stc) and s[i] - 'a' + 'A' == stc.top().L)
				merge(stc.top().R, i + 1), stc.pop();
			else
				while(sz(stc)) stc.pop();
		}
	}
	int q;
	cin >> q;
	while(q--){
		int fi, se;
		cin >> fi >> se;
		fi--;
		cout << (root(fi) == root(se));
	}
	cout << '\n';
	return 0;
}
