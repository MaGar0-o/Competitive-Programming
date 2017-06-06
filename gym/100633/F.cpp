//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
#define log lg

const int maxn = 1e5 + 10;
const LL Mod = 1e9 + 9;
vector<LD> log;
vector<LL> vec,
	pri;
int ans[maxn],
	pw[maxn],
	szans, n;
bool isp[maxn];
LD best = maxn * 2;

void build(int pos = 0, LL div = 1, int mnpos = sz(vec) - 1, LD cur = 0){
	if(cur >= best) return;
	if(div == n){
		szans = pos;
		for(int i = 0; i < pos; i++)
			ans[i] = pw[i];
		best = cur;
		return;
	}
	while(mnpos < sz(vec)){
		if(n % (div * vec[mnpos])){
			mnpos++;
			continue;
		}
		pw[pos] = vec[mnpos] - 1;
		build(pos + 1, div * vec[mnpos], mnpos, cur + log[pos] * pw[pos]);
		mnpos++;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(isp, true, sizeof isp);
	isp[0] = isp[1] = false;
	for(int i = 2; i < maxn; i++)
		if(isp[i]){
			if(i^2)pri.PB(i);
			for(int j = i + i; j < maxn; j += i)
				isp[j] = false;
		}
	for(auto val : pri)
		log.PB(log2(val));
	cin >> n;
	for(int i = n; i > 1; i--)
		if(n % i == 0)
			vec.PB(i);
	build();
	LL ans = 1;
	for(int i = 0; i < szans; i++)
		for(int j = 0; j < ::ans[i]; j++)
			ans = (ans * pri[i]) % Mod;
	cout << ans << '\n';
	return 0;
}
