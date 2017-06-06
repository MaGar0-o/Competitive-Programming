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

LL c[100];

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL Mod = atoi(argv[1]);
	c[0] = 1;
	for (int i = 1; i <= 66; i++)
		for (int j = i; j > 0; j--)
			c[j] = (c[j] + c[j - 1]) % Mod;
	cout << c[33] % Mod << endl;
	return 0;
}
