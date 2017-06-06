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

const int maxn = 1e5 + 10;
LL a[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int id = -1;
	for(int i = 0; i < n; i++)
		if(id == -1 or a[id] < a[i])
			id = i;
	int cnt = count(a, a + n, a[id]);
	bool can = false,
		 can2 = false;
	for(int i = 0; i < n; i++) if(a[i] == a[id]){
		if(i - 1 >= 0){
			if(a[i - 1] < a[i] - 1)
				can = true;
			if(a[i - 1]) can2 = true;
		}
		if(i + 1 < n){
			if(a[i + 1] < a[i] - 1)
				can = true;
			if(a[i + 1]) can2 = true;
		}
	}
	if(cnt > 1)
		cout << (can2 ? min(a[id] + 1, a[id] * (cnt - can)) : a[id] * (cnt - can)) << endl;
	else{
		if(!can)
			cout << a[id] << endl;
		else{
			a[id]--;
			if(id == 0) a[1]++;
			else if(id == n - 1) a[n - 2]++;
			else if(a[id - 1] < a[id + 1]) a[id - 1]++;
			else a[id + 1]++;
			cout << min(a[id] + 1, count(a, a + n, a[id]) * a[id]) << '\n';
		}
	}
	return 0;
}
