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
#define cos cost

const int maxn = 1e5 + 85 - 69;
LL a[maxn],
	mat[maxn],
	cosar[maxn],
	n, k, lst, ans;
set<pll> cos;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> lst, n--;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] -= lst;
		lst += a[i];
	}
	for(int i = 0; i < n; i++){
		mat[i] = i;
		cosar[i] = a[i];
		cos.insert(MP(a[i], i));
	}
	int lm = 0, rm = n - 1;
	for(int i = 0; i < k; i++){
		int id = cos.begin()->R;
		ans += cos.begin()->L;
		cos.erase(cos.begin());
		if(id == lm){
			if(mat[id] == rm) continue;
			int id2 = mat[id] + 1;
			cos.erase(MP(cosar[id2], id2));
			if(id2 >= 0 and id2 < n) lm = mat[id2] + 1;
		}
		else if(mat[id] == rm){
			int id2 = mat[id - 1];
			cos.erase(MP(cosar[id2], id2));
			rm = id2 - 1;
		}
		else{
			int l = mat[id - 1];
			int r = mat[mat[id] + 1];
			cos.erase(MP(cosar[l], l));
			cos.erase(MP(cosar[mat[r]], mat[r]));
			cosar[l] += cosar[mat[r]] - cosar[id];
			mat[l] = r;
			mat[r] = l;
			cos.insert(MP(cosar[l], l));
		}
	}
	cout << ans << endl;
	return 0;
}
