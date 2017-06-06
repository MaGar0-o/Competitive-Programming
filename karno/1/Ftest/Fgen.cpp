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
int mp[maxn],
	pp[maxn],
	bad[maxn];

int main(){
	srand(time(0));
	int n = rand()%(100000 - 10) + 10, k = rand()%(n/2);
	cout << n << ' ' << k << '\n';
	iota(mp, mp + n, 1);
	iota(pp, pp + n, 1);
	random_shuffle(mp, mp + n);
	random_shuffle(pp, pp + n);
	for(int i = 0; i < k; i++)
		bad[i] = 1;
	random_shuffle(bad, bad + n);
	for(int i = 0; i < n; i++)
		cout << pp[i] << ' ';
	cout << '\n';
	for(int i = 0; i < n; i++)
		if(bad[i])
			cout << mp[i] << ' ';
	cout << '\n';
	for(int i = 1; i < n; i++){
		int id = rand()%i;
		cout << mp[i] << ' ' << mp[id] << '\n';
	}
	return 0;
}
