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

const int maxn = 1e6 + 85 - 69;
LL a[maxn * 2],
	cnt[maxn];
LL n, k;
set<int> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> n;
	for(int i = 0; i < k; i++){
		cin >> a[i], a[i]--;
		if(a[i] <= k)
			cnt[a[i]]++;
	}
	for(int i = 0; i <= k; i++)
		if(!cnt[i])
			s.insert(i);
	for(int i = k; i <= k + k; i++){
		a[i] = *s.begin();
		cnt[a[i]]++;
		s.erase(a[i]);
		if(a[i - k] <= k){
			cnt[a[i - k]]--;
			if(cnt[a[i - k]] == 0)
				s.insert(a[i - k]);
		}
	}
	n--;
	if(n < k)
		cout << a[n] + 1 << endl;
	else
		cout << 1+a[k + ((n-k) % (k+1))] << endl;
	return 0;
}
