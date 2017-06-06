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

#define int LL

const int maxn = 100;
int a[maxn];
int n;

int getmin(int val){
	int xh = 9999999999999999;
	for(int i = 0; i < n; i++)
		if(a[i] == val){
			stringstream ss;
			stringstream ret;
			ss << i;
			ret << xh;
			if(ss.str() < ret.str())
				xh = i;
		}
	return xh;
}

int getd(int val){
	int ret = 0;
	while(val){
		ret++;
		val /= 10;
	}
	return ret;
}

int get(int lo, int hi){
	int dlo = getd(lo),
		dhi = getd(hi);
	if(dlo < dhi){
		int ret = 1;
		for(int i = 0; i < dlo; i++) ret *= 10;
		return ret;
	}
	return lo + 1;
}

void print(int x, int y){
	cout << "CAKE " << x << " PIECES " << y << endl;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(n == 1){
		print(0, a[0]);
		return 0;
	}
	int mx1 = *max_element(a, a + n);
	int cnt = count(a, a + n, mx1);
	int id = getmin(mx1);
	if(~-cnt)
		print(id, 1);
	else{
		(*max_element(a, a + n)) = -1;
		int mx2 = *max_element(a, a + n);
		int cnt2 = count(a, a + n, mx2);
		int dif = mx1 - mx2;
		if((cnt2 & 1) or mx2 == 0)
			print(id, dif);
		else
			print(id, get(dif, mx1));
	}
	return 0;
}
