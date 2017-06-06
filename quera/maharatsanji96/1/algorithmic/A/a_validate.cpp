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

const int maxn = 1e6 + 10;
int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//get n
	string buf;
	getline(cin, buf);
	assert(cin.good());
	int n = stoi(buf);
	assert(buf == to_string(n));
	assert(n >= 1);
	assert(n <= 1000000);

	//get array
	getline(cin, buf);
	assert(cin.good());
	assert(count(all(buf), ' ') == n - 1);
	int prv = -1;
	for (int i = 0; i < n; i++) {
		int id = find(buf.begin() + prv + 1, buf.end(), ' ') - buf.begin();
		string num = buf.substr(prv + 1, id - prv - 1);
		a[i] = stoi(num);
		assert(to_string(a[i]) == num);
		assert(a[i] <= +1000000000);
		assert(a[i] >= -1000000000);
		prv = id;
	}
	getline(cin, buf);
	assert(!cin.good());
	LL neg = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < 0)
			neg++;
	cout << neg * (n - 1) << '\n';
	return 0;
}
