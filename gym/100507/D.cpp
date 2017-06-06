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

const int maxn = 1000;
pii fri[maxn];
int mx[maxn];
int n, m;
int memon, adv1, adv2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> memon >> adv1 >> adv2;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> fri[i].L >> fri[i].R;
	sort(fri, fri + n);
	mx[n - 1] = n - 1;
	for(int i = n - 2; i >= 0; i--){
		mx[i] = mx[i + 1];
		if(fri[i].R > fri[mx[i]].R)
			mx[i] = i;
	}
	cin >> m;
	LL mxans = -1,
	   aid = -1,
	   pid = -1,
	   fid = -1;
	for(int i = 0; i < m; i++){
		int peo, cos, adv;
		cin >> peo >> cos >> adv;
		if(memon >= cos){
			if(peo == 1 and adv1 + adv >= mxans)
				aid = i, pid = 1, mxans = adv + adv1;
			else if(peo == 2 and adv2 + adv >= mxans)
				aid = i, pid = 1, mxans = adv + adv2;
		}
		int id = lower_bound(fri, fri + n, MP((cos+1)>>1, -1)) - fri;
		if(id == n or peo != 2 or ((cos+1)>>1) > memon) continue;
		if(fri[mx[id]].R + adv >= mxans)
			aid = i, pid = 2, fid = mx[id], mxans = mx[id] + adv;
	}
	if(aid == -1)
		cout << "Forget about apartments. Live in the dormitory.";
	else if(pid == 1)
		cout << "You should rent the apartment #" << aid + 1 << " alone.";
	else
		cout << "You should rent the apartment #" << aid+1 << " with the friend #" << fid+1 << ".";
	return 0;
}
