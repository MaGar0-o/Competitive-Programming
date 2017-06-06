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
string s;
int ord[maxn];
int n;

bool cmp(int i, int j){
	return MP(s[i], i) < MP(s[j], j);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	n--;
	iota(ord, ord + sz(s), 0);
	sort(ord, ord + sz(s), cmp);
	for(int i = 0; i < sz(s); i++)
		cout << s[n = ord[n]];
	cout << endl;
	return 0;
}
