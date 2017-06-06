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

const int maxn = 100 + 5,
	  maxl = 55;
const LL Inf = 1e18;
int n;
LL T;
LL year[maxn];
vector<int> vec[maxn];

struct matrix{
	LL a[maxn][maxn];
	matrix(LL def = Inf){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				a[i][j] = def;
		return;
	}
	LL getmin(void){
		LL ret = a[0][0];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				smin(ret, a[i][j]);
		return ret;
	}
	LL* operator[](int i){ return a[i];}
	void print(void){
		for(int i = 0; i < n; i++, cout << endl)
			for(int j = 0; j < n; j++)
				cout << a[i][j] << ' ';
		cout << endl;
	}
} dis[maxl];

matrix operator*(matrix &A, matrix &B){
	matrix ret(Inf);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				ret[i][j] = min(ret[i][j], A[i][k] + B[k][j]);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < maxl; i++)
		for(int j = 0; j < maxn; j++)
			for(int k = 0; k < maxn; k++)
				dis[i][j][k] = Inf;
	cin >> n >> T;
	for(int i = 0; i < n; i++){
		int cnt;
		cin >> cnt >> year[i];
		while(cnt--){
			int x;
			cin >> x, x--;
			vec[i].PB(x);
		}
		for(int j = 0; j < sz(vec[i]); j++){
			int tmp;
			cin >> tmp;
			smin(dis[0][i][vec[i][j]], tmp + year[i]);
		}
	}
	/*for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				smin(dis[0][i][j], dis[0][i][k] + dis[0][k][j]);
	*/for(int id = 1; id < maxl; id++)
		dis[id] = dis[id - 1] * dis[id - 1];
	//dis[0].print();
	//dis[1].print();
	matrix cur(0);
	LL ans = 0;
	for(int i = maxl - 1; i >= 0; i--){
		matrix tmp = cur * dis[i];
		if(tmp.getmin() <= T)
			cur = tmp, ans += 1LL << i;
	}
	cout << ans << '\n';
	return 0;
}
