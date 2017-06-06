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

string valid_strings[6] = {
	"aaabbbc",
	"aaabccc",
	"abbbccc",
	"aabbccc",
	"aabbbcc",
	"aaabbcc"
};
int valid_mask[6];

bool is_valid(int num) {
	vector<int> bignum;
	for (int i = 0; i < 7; i++, num /= 10)
		bignum.PB(num % 10);
	int mask = 0;
	bool yekidarmiun = true;
	for (int i = 1; i < 7; i++) {
		if (i >= 2 and bignum[i] != bignum[i - 2])
			yekidarmiun = false;
		int c = bignum[i] == bignum[i - 1];
		mask |= c << i;
	}
	if (yekidarmiun)
		return true;
	for (int i = 0; i < 6; i++)
		if ((valid_mask[i] & mask) == valid_mask[i])
			return true;
	return false;
}

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL Mod = atoi(argv[1]);
	for (int _ = 0; _ < 6; _++) {
		int mask = 0;
		for (int i = 1; i < 7; i++) {
			int c = valid_strings[_][i] == valid_strings[_][i - 1];
			mask |= c << i;
		}
		valid_mask[_] = mask;
	}
	LL ans = 0;
	for (int i = 1000000; i < 7801389; i++)
		ans += is_valid(i);
	cout << (ans * ans) % Mod << endl;
	return 0;
}
