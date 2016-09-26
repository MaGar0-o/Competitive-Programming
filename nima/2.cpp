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

int a[12];
LL ans;
const int n = 12;

bool check(void){
	for(int i = 0; i < n; i++){
		bool an = true;
		for(int j = 0; j < 6; j++)
			if(a[(i + j) % n] != j){
				an = false;
				break;
			}
		if(an)
			return true;
	}
	return false;
}

void build(int pos = 0){
	if(pos == n){
		ans += check();
		return;
	}
	for(int i = 0; i < 6; i++){
		a[pos] = i;
		build(pos + 1);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	build();
	cout << ans << endl;
	return 0;
}
