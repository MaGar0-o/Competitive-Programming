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

const int maxn = 1e6 + 85 - 69,
	  maxsq = 200;
const LL Mod = 1e9 + 7;
LL func[maxn];
int le[maxn],
	ri[maxn],
	ord[maxn],
	cnt[maxn],
	a[maxn],
	n, c, q;

bool cmp(int i, int j){
	return le[i] / maxsq == le[j] / maxsq ? ri[i] < ri[j] : le[i] > le[j];
}

LL Pow(LL x, LL y){
	LL an = x,
	   ret = 1;
	while(y){
		if(y & 1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y >>= 1;
	}
	return ret;
}

LL Div(LL x, LL y){return (x * Pow(y, Mod - 2)) % Mod;}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> c >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i <= n; i++)
		cin >> func[i];
	for(int i = 0; i < q; i++){
		cin >> le[i] >> ri[i];
		le[i]--, ri[i]--;
		ord[i] = i;
	}
	sort(ord, ord + q, cmp);
	int st = 0, en = -1;
	LL val = Pow(func[0], c), ans = 1;
	for(int i = 0; i < q; i++){
		while(st > le[ord[i]]){
			st--;
			val = Div(val, func[cnt[a[st]]]);
			cnt[a[st]]++;
			val = (val * func[cnt[a[st]]]) % Mod;
		}
		while(en < ri[ord[i]]){
			en++;
			val = Div(val, func[cnt[a[en]]]);
			cnt[a[en]]++;
			val = (val * func[cnt[a[en]]]) % Mod;
		}
		while(st < le[ord[i]]){
			val = Div(val, func[cnt[a[st]]]);
			cnt[a[st]]--;
			val = (val * func[cnt[a[st]]]) % Mod;
			st++;
		}
		while(en > ri[ord[i]]){
			val = Div(val, func[cnt[a[en]]]);
			cnt[a[en]]--;
			val = (val * func[cnt[a[en]]]) % Mod;
			en--;
		}
		ans = (ans * val) % Mod;
	}
	cout << ans << '\n';
	return 0;
}
