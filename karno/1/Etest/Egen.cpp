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

int wei[500000];
int mp[500000];
int ord[500000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));
	int n = 500;//*2;
	int q = n - 1;
	cout << n << ' ' << q << '\n';
	for(int i = 0; i < n - 1; i++)
		wei[i] = rand() % 1000000000;
	iota(mp, mp + n, 0);
	random_shuffle(mp,mp + n);
	for(int i = 1; i < n; i++){
		int id = rand()%i;
		cout << mp[i]+1 << ' ' << mp[id]+1 << ' ' << wei[i - 1] << '\n';
	}
	iota(ord, ord + n - 1, 1);
	random_shuffle(ord, ord + n - 1);
	for(int i = 0; i < n - 1; i++)
		cout << ord[i] << ' ';
	cout << '\n';
	return 0;
}
