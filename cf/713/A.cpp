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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		char ty;
		string str;
		cin >> ty >> str;
		for(auto &c : str)
			c &= 1;
		if(ty == '+' or ty == '-'){
			while(sz(str) < 18) str = "0" + str;
			str = "000000000000000000" + str;

	}
	return 0;
}
