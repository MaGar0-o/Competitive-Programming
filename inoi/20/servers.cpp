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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(i < j) dis.insert(MP(a[i][j], MP(i, j)));
		}
	}
	LL ans = 0;
	for(int i = 1; i < n; i++){
		int u = dis.begin()->R.L,
			v = dis.begin()->R.R;
		dis.erase(dis.begin());
		ans += a[u][v];
		mark[v] = true;
		if(i != n - 1){
			for(int j = 0; j < n; j++)
				if(j != u and !mark[j]){
					int val = (a[u][j] + a[v][j] - a[u][v]) / 2;
					val = a[u][j] - val;
					for(int k = 0; k < n; k++)
						if(!mark[k]){
							a[u][k] -= val;
							if(
		}
	}
	return 0;
}
