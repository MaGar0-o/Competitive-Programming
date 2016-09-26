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

const int maxn = 1000 + 10;
int ty[10] = {1, 1, 0, 0, 0, 0, 2, 0, 1, 2};
int  f[10] = {0, 1, 5, 5, 5, 5, 9, 5, 8, 6};
int cnt[100000];
int a[maxn];
int n, k;

int intof(string &s){
	int ret = 0;
	for(int i = 0; i < sz(s); i++)
		ret = ret * 10 + s[i] - '0';
	return ret;
}

int makoos(int x){
	if(x % 10 == 0)
		return -1;
	int ret = 0;
	while(x){
		if(ty[x % 10] == 0)
			return -1;
		ret = ret * 10 + f[x % 10];
		x /= 10;
	}
	return ret;
}

void solve(void){
	memset(cnt, 0, sizeof cnt);
	cin >> n >> k;
	bool an = false;
	for(int i = 0; i < k; i++){
		string s, t;
		cin >> s;
		t = s;
		reverse(all(t));
		if(s[0] == '0' and t[0] == '0')
			an = true;
		else if(s[0] == '0')
			a[i] = intof(t);
		else
			a[i] = intof(s);
		if(makoos(a[i]) != -1)
			cnt[min(a[i], makoos(a[i]))]++;
		else
			cnt[a[i]]++;
	}
	if(an){
		cout << "YES\n" << endl;
		return;
	}
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += cnt[i];
		if(cnt[i] >= 3){
			cout << "YES\n";
			return;
		}
		else if(cnt[i] == 2 and (makoos(i) == -1 or makoos(i) > n or makoos(i) == i)){
			cout << "YES\n";
			return;
		}
	}
	if(sum != k){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	//while(cin >> t) cout << makoos(t) << endl;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
