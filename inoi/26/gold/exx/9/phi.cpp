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

const int maxn = 1e5 + 10;
int phi[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		phi[i] = i - phi[i];
		for(int j = i + i; j <= n; j += i)
			phi[j] += phi[i];
		sum += phi[i];
	}
	cout << sum << endl;
	return 0;
}
