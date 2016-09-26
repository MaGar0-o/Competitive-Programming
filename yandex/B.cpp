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
int a[maxn],
	n,
	ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i & 1) a[i] = -a[i];
	}
	n = unique(a, a + n) - a;
	/*for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;*/
	for(int i = 0; i < n;){
		while(i < n and a[i] == 0) i++;
		if(i == n) break;
		int ptr = i;
		while(ptr < n and a[ptr]) ptr++;
		ans += (ptr - i) / 2 + 1;
		//cout << i << ' ' << ptr << endl;
		i = ptr;
	}
	cout << ans << '\n';
	return 0;
}
