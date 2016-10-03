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
LL n, L, a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> L;
	int pos = -1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i and a[i] + a[i - 1] >= L) pos = i - 1;
	}
	if(pos == -1){
		cout << "Impossible\n";
		return 0;
	}
	cout << "Possible\n";
	for(int i = 0; i < pos; i++)
		cout << i + 1 << '\n';
	for(int i = n - 2; i > pos; i--)
		cout << i + 1 << '\n';
	cout << pos + 1 << '\n';
	return 0;
}
