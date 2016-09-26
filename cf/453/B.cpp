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

int a[100];
int ans;

void build(int pos, int num){
	if(num == 60){
		ans++;
		return;
	}
	build(pos, num+1);
	for(int i = 0; i < pos; i++)
		if(__gcd(a[i], num) != 1)
			return;
	a[pos] = num;
	build(pos + 1, num + 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	build(0, 2);
	cout << ans << endl;
	return 0;
}
