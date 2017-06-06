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

const int maxn = 200 + 10;
string fib[maxn];
bool pre[maxn][maxn],
	 suf[maxn][maxn];
vector<int> ans[maxn];
string s;
int n;

void plusplus(vector<int> &vec){
	vec[0]++;
	for(int i = 0; i < sz(vec); i++){
		if(vec[i] < 10) return;
		vec[i] -= 10;
		if(i+1 < sz(vec))
			vec[i + 1]++;
		else
			vec.PB(1);
	}
	return;
}

vector<int> operator+(vector<int> &A, vector<int> &B){
	if(sz(A) < sz(B)) swap(A, B);
	vector<int> ret = A;
	for(int i = 0; i < sz(B); i++){
		ret[i] += B[i];
		if(ret[i] >= 10)
			if(i + 1 == sz(ret)) ret.PB(1), ret[i] -= 10;
			else ret[i + 1]++, ret[i] -= 10;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> n;
	for(int i = 1; i < maxn; i++)
		ans[i].PB(0);
	fib[1] = "b";
	fib[2] = "a";
	int cur = 2;
	while(sz(fib[cur]) <= 100)
		fib[++cur] = fib[cur] + fib[cur - 1];
	for(int i = 1; i <= cur; i++)
		for(int j = 0; j <= sz(fib[i]) - sz(s); j++)
			if(fib[i].substr(j, sz(s)) == s)
				plusplus(ans[i]);
	for(int i = cur - 1; i <= cur; i++){
		for(int len = 1; len <= sz(s); len++){
			pre[i][len] = s.substr(sz(s) - len, len) == fib[i].substr(0, len);
			suf[i][len] = s.substr(0, len) == fib[i].substr(sz(fib[i]) - len, len);
		}
	}
	for(int i = cur + 1; i <= n; i++){
		ans[i] = ans[i - 1] + ans[i - 2];
		for(int j = 1; j < sz(s); j++){
			pre[i][j] = pre[i - 1][j];
			suf[i][j] = suf[i - 2][j];
			if(suf[i - 1][j] and pre[i - 2][sz(s) - j]) plusplus(ans[i]);
		}
	}
	for(int i = sz(ans[n]) - 1; i >= 0; i--)
		cout << ans[n][i];
	cout << '\n';
	return 0;
}
