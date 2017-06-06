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

string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a[1024][1024];
	getline(cin, str);
	int n = stoi(str);
	assert(sz(to_string(n)) == sz(str));
	int cnt = 0;
	bool caps = false;
	string ret;
	while (getline(cin, str)) {
		cnt++;
		a[cnt][cnt] = a[cnt - 1][cnt - 1] + 10;
		assert(cnt <= n);
		assert(sz(str) == 1 or sz(str) == 4);
		if (sz(str) == 1) {
			assert(str[0] >= 'a' and str[0] <= 'z');
			if(caps) ret += str[0] - 'a' + 'A';
			else ret += str[0];
		}
		else {
			assert(str == "CAPS");
			caps = !caps;
		}
	}
	cout << a[1023][1023];
	cout << ret << endl;
	return 0;
}
