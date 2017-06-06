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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	const int n = sz(s);
	LL ans = -1;
	for(int i = 0; i < n; i++) if(s[0] != '0' or i == 0)
		for(int j = i + 1; j + 1 < n; j++) if(s[i + 1] != '0' or j == i + 1) if(s[j + 1] != '0' or j + 1 == n - 1){
			LL num1 = 0,
			   num2 = 0,
			   num3 = 0;
			for(int l = 0; l <= i; l++)
				num1 = num1 * 10 + s[l] - '0';
			for(int l = i + 1; l <= j; l++)
				num2 = num2 * 10 + s[l] - '0';
			for(int l = j + 1; l < n; l++)
				num3 = num3 * 10 + s[l] - '0';
			if(max(max(num1, num2), num3) > 1000LL * 1000)
				continue;
			smax(ans, num1 + num2 + num3);
		}
	cout << ans << endl;
	return 0;
}
