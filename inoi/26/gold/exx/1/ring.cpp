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

const int maxn = 1e4 + 85 - 69;
LL val[maxn * 3],
   a[maxn], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	rotate(a, a + 1, a + n);
	for(int i = 2; i < n * 2 + 2; i++)
		val[i] = a[(i - 2) % n] - (val[i - 1] + val[i - 2]);
	if(n % 3 == 0){
		LL val1 = 1,
		   val2 = 1;
		for(int i = 0; i < n; i += 3)
			smax(val1, -val[i] + 1);
		for(int i = 1; i < n; i += 3)
			smax(val2, -val[i] + 1);
		for(int i = 0; i < n; i++){
			if(i % 3 == 0)
				cout << val[i] + val1 << ' ';
			else if(i % 3 == 1)
				cout << val[i] + val2 << ' ';
			else
				cout << val[i] - (val1 + val2) << ' ';
		}
		cout << endl;
		return 0;
	}
	LL x = (val[n] + val[n + n]) / 3;
	LL mx = max(val[n], val[n + n]);
	LL mn = min(val[n], val[n + n]);
	LL y = (mx - 2 * mn) / 3;
	for(int i = 0; i < n; i++){
		if(i % 3 == 0)
			val[i] += x;
		else if(i % 3 == 1)
			val[i] += y;
		else
			val[i] -= x + y;
	}
	for(int i = 0; i < n; i++)
		cout << val[i] << ' ';
	cout << '\n';
	return 0;
}
