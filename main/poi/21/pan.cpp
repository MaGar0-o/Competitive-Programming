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

vector<int> vec;

void calc(int a){
	int x = 1;
	while(x <= a){
		//cout << x << endl;
		x += (a%x)/(a/x);
		vec.PB(x);
		x++;
	}
	return;
}

void solve(void){
	int l1, l2, r1, r2;
	cin >> l1 >> r1 >> l2 >> r2,
		l1--, l2--;
	vec.clear();
	calc(r1);
	calc(r2);
	int ans = 1;
	for(int i = 0; i < sz(vec); i++){
		int val = vec[i];
		if(r1/val - l1/val and r2/val - l2/val)
			smax(ans, val);
	}
	cout << ans << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
