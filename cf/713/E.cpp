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

const int maxn = 1e5 + 85 - 69;
int a[maxn];
bool mark[maxn];
int n, m;
vector<int> dis;

int dist(int i, int j){
	if(i < j) return a[j] - a[i] - 1;
	return m - 2 - dist(j, i);
}

bool check(int tim){
	bool ret = true;
	for(int i = 0; i < n; i++) if(dis[i] > tim){
		if(dis[i] > 2 * tim) return false;
		int p = i+1;
		bool cur = false;
		while(dis[p] <= tim) p++;
		if(p == i + 1) return false;
		if(p == i + 2){

		}
		for(int j = i; j <= p; j++)
			if(dis[j] == 0)
				cur = true;
		for(int j = i + 2; j + 2 <= p; j++)
			if((dis[j - 1] + dis[j] + 1) <= tim and (dis[j] + dis[j + 1] + 1) <= tim)
				cur = true;
		ret &= cur;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i], a[i]--;
	if(n == 1){
		cout << m - 1 << '\n';
		return 0;
	}
	for(int i = 0; i < n; i++)
		dis.PB(dist(i, (i + 1) % n));
	for(int i = 0; i < n; i++)
		dis.PB(dis[i]);
	for(auto val : dis)
		cout << val << ' ';
	cout << endl;
	int lo = -1,
		hi = 1000 * 1000 * 1000;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << '\n';
	return 0;
}
