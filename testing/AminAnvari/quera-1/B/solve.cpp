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

const int maxn = 1e5 + 85 - 69;
LL a[maxn];
int n;

LL get(int st, int en){
	LL ret = 0;
	for(int i = st; i < en; i++)
		ret += a[i];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++) if(n % i == 0){
		LL sum = get(0, i);
		bool can = true;
		for(int j = i; j < n; j += i)
			if(get(j, j + i) != sum)
				can = false;
		if(can){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
