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

const int maxn = 50 * 50;
int match[maxn],
	n, n2;
bool mark[maxn];

bool dfs(int u){
	if(mark[u]) return false;
	mark[u] = true;
	if(u - n >= 0 and !mark[u - n] and (match[u - n] == -1 or dfs(match[u - n]))){
		match[u] = u - n;
		match[u - n] = u;
		return true;
	}
	if(u + n < n2 and !mark[u + n] and (match[u + n] == -1 or dfs(match[u + n]))){
		match[u] = u + n;
		match[u + n] = u;
		return true;
	}
	if(u % n and !mark[u - 1] and (match[u - 1] == -1 or dfs(match[u - 1]))){
		match[u] = u - 1;
		match[u - 1] = u;
		return true;
	}
	if(u % n != n - 1 and !mark[u + 1] and (match[u + 1] == -1 or dfs(match[u + 1]))){
		match[u] = u + 1;
		match[u + 1] = u;
		return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(match, -1, sizeof match);
	int a, b, c;
	cin >> n >> a >> b >> c;
	a--, b--, c--;
	n2 = n * n;
	int k = (n2 - 3) / 2;
	bool fnd = true;
	int ans = 0;
	while(fnd){
		fnd = false;
		memset(mark, false, sizeof mark);
		mark[a] = mark[b] = mark[c] = true;
		for(int i = 0; i < n2; i++){
			if(match[i] == -1 and dfs(i))
				ans++, fnd = true;
		}
	}
	memset(mark, false, sizeof mark);
	mark[a] = mark[b] = mark[c] = true;
	if(ans == k){
		for(int i = 0; i < n2; i++)
			if(!mark[i]){
				cout << i+1 << ' ' << match[i]+1 << '\n';
				mark[match[i]] = true;
			}
	}
	else
		cout << "NIE\n";
	return 0;
}
