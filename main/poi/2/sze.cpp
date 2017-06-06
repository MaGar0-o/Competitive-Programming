//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 1e4 + 10;
int ord[maxn],
	n;
LD a[maxn],
   b[maxn];

bool cmp(int i, int j){
	return a[j] * b[i] + b[j] + b[i] < a[i] * b[j] + b[i] + b[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		ord[i] = i;
	}
	/*LD tim = 0;
	for(int i = 0; i < n; i++){
		cin >> ord[i], ord[i]--;
		tim += a[ord[i]] * tim + b[ord[i]];
	}*/
	sort(ord, ord + n, cmp);
	for(int i = 0; i < n; i++)
		cout << 1+ord[i] << '\n';
	return 0;
}
