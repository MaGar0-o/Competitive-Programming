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

const int maxn = 2e5 + 85 - 69;
pii pos[maxn];
int a[maxn],
	n;

void Swap(int i, int j){
	if(pos[a[j]].L == j){
		pos[a[j]].L = i;
		if(pos[a[j]].L > pos[a[j]].R)
			swap(pos[a[j]].L, pos[a[j]].R);
	}
	else{
		pos[a[j]].R = i;
		if(pos[a[j]].L > pos[a[j]].R)
			swap(pos[a[j]].L, pos[a[j]].R);
	}
	swap(a[i], a[j]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fill(pos, pos + maxn, pii(-1, -1));
	cin >> n;
	for(int i = 0; i < n + n; i++){
		cin >> a[i], a[i]--;
		if(pos[a[i]].L == -1) pos[a[i]].L = i;
		else pos[a[i]].R = i;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == a[i + n])
			continue;
		Swap(pos[a[i]].R, i + n);
		ans++;
	}
	cout << ans << '\n';
	return 0;
}
