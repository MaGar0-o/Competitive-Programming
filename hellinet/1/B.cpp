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

const int maxn = 2e5 + 100;
int a[maxn];
int n;
vector<int> vec;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for(int i = 1; 1LL * i * i <= a[n - 1]; i++) if(a[n - 1] % i == 0){
		vec.PB(i);
		if(i * i == a[n - 1]) break;
		vec.PB(a[n - 1]/i);
	}
	sort(all(vec));
	if(sz(vec) != n){
		cout << "no" << endl;
		return 0;
	}
	for(int i = 0; i < n; i++)
		if(a[i] != vec[i]){
			cout << "no" << endl;
			return 0;
		}
	cout << "yes" << endl;
	return 0;
}
