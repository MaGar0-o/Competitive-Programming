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
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	memset(dis, 63, sizeof dis);
	dis[a[0]][a[1]][a[2]][a[3]] = 0;
	q[sz++] = MP(MP(a[0], a[1]), MP(a[2], a[3]));
	for(int i = 0; i < sz; i++){
		a[0] = q[i].L.L;
		a[1] = q[i].L.R;
		a[2] = q[i].R.L;
		a[3] = q[i].R.R;
		int &d = dis[a[0]][a[1]][a[2]][a[3]];
		for(int j = 0; j < n; j++) if(a[j]){
			int tmp = a[j];
			a[j] = 0;
			if(d + 1 < dis[a[0]][a[1]][a[2]][a[3]]){
				dis[a[0]][a[1]][a[2]][a[3]] = d + 1;
				q[sz++] = MP(MP(a[0], a[1]), MP(a[2], a[3]));
			}
			a[j] = tmp;
			for(int k = 0; k < n; k++) if(k^j){
				int gt = 
			}
		}
	}
	return 0;
}
