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

int LEN(int val){
	int ret = 1;
	while(val)
		ret++, val /= 10;
	return ret;
}

void add_alt(int a, int b){
	if(a == b)
		ss << a << ',';
	else
		ss << a << (a&1 ? '#' : '%') << b << ',';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = 1; i <= n; i++)
		len[i] = LEN(a[i]);
	return 0;
}
