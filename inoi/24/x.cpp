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

int fi[100], en[100];
bool mark[100];
int ans;
int n, len;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> len;
	for(int i = 0; i < n; i++)
		cin >> fi[i] >> en[i];
	for(int mask = 0; mask < (1 << n); mask++){
		memset(mark, false, sizeof mark);
		for(int i = 0; i < n; i++)
			if((mask >> i) & 1)
				for(int j = fi[i]; j < en[i]; j++)
					mark[j] = true;
		bool an = true;
		for(int i = 0; i < len; i++)
			if(!mark[i])
				an = false;
		ans += an;
		if(an){
			for(int i = 0; i < n; i++)
				if((mask >> i) & 1)
					cout << i << ' ';
			cout << endl;
		}
	}
	cout << ans << endl;
	return 0;
} 
