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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	int n = 5,
		q = 20;
	cout << n << ' ' << q << '\n';
	for(int i = 0; i < n; i++)
		cout << (rand()&3) << ' ';
	cout << '\n';
	for(int i = 0; i < q; i++){
		int ty = rand()&1;
		int fi = rand() % n + 1,
			se = rand() % n + 1;
		if(fi > se) swap(fi, se);
		cout << ty + 1 << ' ' << fi << ' ' << se << ' ';
		if(!ty)
			cout << (rand()&3) << ' ';
		cout << '\n';
	}
	return 0;
}
