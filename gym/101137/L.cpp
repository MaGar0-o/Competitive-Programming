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

const int maxn = 2e5 + 85 - 69;
LL tim[maxn],
   su[maxn],
   ty[maxn];
LD ans[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n+n; i++){
		char c;
		cin >> c >> tim[i];
		ty[i] = (c == '+' ? +1 : -1);
		su[i + 1] = su[i] + ty[i];
	}
	LD cur = 0;
	for(int i = n+n-1; i >= 0; i--){
		if(ty[i] == -1)
			cur *= LD(su[i] - 1) / su[i];
		else
			ans[i] = cur;
		if(i)
			cur += tim[i] - tim[i - 1];
	}
	cout << fixed << setprecision(10);
	for(int i = 0; i < n+n; i++)
		if(ty[i] == +1)
			cout << ans[i] << '\n';
	return 0;
}
