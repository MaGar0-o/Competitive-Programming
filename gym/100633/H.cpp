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

int func(int len){
	if(len <= 3)
		return len - 1;
	return func(len - 3) + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, s, f;
	cin >> n >> s >> f;
	if(s > f){
		s = n + 1 - s;
		f = n + 1 - f;
	}
	if(s == 1){
		if(f == n)
			cout << func(n) << '\n';
		else
			cout << func(f - 1) + 1 << '\n';
	}
	else{
		if(f == n)
			cout << 1 + func(f - s) << '\n';
		else if(f - s - 1 > 0)
			cout << 2 + func(f - s - 1) << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}
