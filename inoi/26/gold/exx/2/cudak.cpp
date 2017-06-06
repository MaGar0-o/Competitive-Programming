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

LL dp[20][200];
LL a, b, s;

LL func(LL num){
	vector<int> vec;
	for(int i = 0; i < 16; i++)
		vec.PB(num % 10), num /= 10;
	reverse(all(vec));
	LL ret = 0, curs = 0;
	for(int i = 0; i < sz(vec); i++){
		for(int j = 0; j < vec[i]; j++)
			if(s - curs - j >= 0)
				ret += dp[sz(vec) - i - 1][s - curs - j];
		curs += vec[i];
	}
	return ret;
}

LL get_big(LL num){
	vector<int> vec;
	for(int i = 0; i < 16; i++)
		vec.PB(num % 10), num /= 10;
	reverse(all(vec));
	int su = 0,
		curs = s;
	for(auto d : vec) su += d;
	for(int i = sz(vec) - 1; i >= 0; i--){
		su -= vec[i];
		for(int j = vec[i] + 1; j < 10; j++)
			if(su + j <= s and su + j + 9 * (sz(vec) - i - 1) >= s){
				vec[i] = j;
				curs -= su + j;
				for(int k = sz(vec) - 1; k > i; k--){
					vec[k] = min(9, curs);
					curs -= min(curs, 9);
				}
				LL ret = 0;
				for(auto d : vec) ret = ret * 10 + d;
				return ret;
			}
	}
	return 69;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> b >> a >> s;
	dp[0][0] = 1;
	for(int i = 1; i < 20; i++)
		for(int j = 0; j <= 150; j++)
			for(int k = 0; k < 10; k++)
				if(j >= k)
					dp[i][j] += dp[i - 1][j - k];
	cout << func(a + 1) - func(b) << '\n' << get_big(b - 1) << endl;
	return 0;
}
