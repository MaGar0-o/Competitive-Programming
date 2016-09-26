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
#define fnd FND
#define count COUNT

const int maxn = 5e5 + 85 - 69;
vector<int> vec[maxn];
int a[maxn],
	n, q;

int count(int x, int le, int ri){
	return lower_bound(all(vec[x]), ri)
		- lower_bound(all(vec[x]), le);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i], vec[a[i]].PB(i);
	for(int i = 0; i < q; i++){
		int fi, se;
		bool fnd = false;
		cin >> fi >> se, fi--;
		for(int j = 0; j < 10; j++){
			int id = fi + (rand() % (se - fi));
			if(count(a[id], fi, se) > (se - fi) / 2){
				cout << a[id] << '\n';
				fnd = true;
				break;
			}
		}
		if(!fnd)
			cout << 0 << '\n';
	}
	return 0;
}
