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

int n;
int a[100],
	b[100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		char c;
		int v;
		cin >> c >> v;
		string s = "RGBYW";
		a[i] = find(all(s), c) - s.begin();
		b[i] = v - 1;
	}
	int ans = 10;
	for(int mask1 = 0; mask1 < 32; mask1++)
		for(int mask2 = 0; mask2 < 32; mask2++){
			bool yes = true;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if(a[i] != a[j] and b[i] != b[j]){
						if(((mask1>>a[i])&1) and ((mask1>>a[j])&1))
							if(((mask2>>b[i])&1) and ((mask2>>b[j])&1))
								yes = false;
					}
					else if(a[i] == a[j] and b[i] != b[j]){
						if(mask >> 
					}
			if(yes)
				smin(ans, 10 - __builtin_popcount(mask1) - __builtin_popcount(mask2));
		}
	cout << ans << endl;
	return 0;
}
