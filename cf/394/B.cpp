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

bool func(int dig, int pos = 0, int cur = -1){
	if(cur == -1) cur = dig;
	if(pos == p and cur == dig){
		print();
		return true;
	}
	`
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> p >> mul;
	for(int i = 1; i < 10; i++)
		if(func(i))
			return 0;
	cout << "Impossible\n";
	return 0;
}
