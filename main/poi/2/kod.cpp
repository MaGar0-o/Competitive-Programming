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

const int maxn = 1<<15;
int fen[maxn],
	a[maxn],
	n;

int get(int k){
	int ret = 0;
	for(int i = 14; i >= 0; i--)
		if((1 << i) - fen[ret + (1<<i)] <= k){
			ret += 1<<i;
			k -= (1 << i) - fen[ret];
		}
	if(k){
		cout << "NIE\n";
		exit(0);
	}
	return ret + 1;
}

void inc(int idx){
	while(idx < maxn){
		fen[idx]++;
		idx += idx & -idx;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], a[i] = i - a[i];
	for(int i = n - 1; i >= 0; i--)
		inc(a[i] = get(a[i]));
	for(int i = 0; i < n; i++)
		cout << (i?"\n":"") << a[i];
	return 0;
}
