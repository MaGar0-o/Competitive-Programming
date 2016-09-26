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

const int maxn = 20000 + 10;
LL w[maxn], t[maxn], ord[maxn];

bool cmp(int i, int j){
	return t[i] != t[j] ? t[i] < t[j] : w[i] > w[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i] >> w[i], ord[i] = i;
	sort(ord, ord + n, cmp);
	LL ans = 0, sum = 0;
	for(int i = 0; i < n; i++){
		sum += t[ord[i]];
		ans += sum * w[ord[i]];
	}
	cout << ans << endl;
	return 0;
}
