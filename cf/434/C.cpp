//sobskdrbhvk
//khodam midoonam bedoon e aho ham mishe accept kard, vali ensafan niga aho che khoshgele :) delet miad aho nazani aslan? :(
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

const int maxn = 200 + 85 - 80,
	  maxm = 20,
	  maxk = 500 + 85 - 80,
	  Mod = 1e9 + 7;
int dp[maxn][maxn][maxk],
	go[maxn][maxm],
	fail[maxn],
	scr[maxn],
	ahoscr[maxn],
	n, m, k, sz = 1;
vector<int> lnum, rnum,
	num[maxn];
queue<int> q;

LL dplow(vector<int> &num, int pos = 0, int state = 0, int rem = k){
	if(rem < 0 or pos == sz(num)) return 0;
	LL ret = 0;
	for(int i = (pos == 0); i < num[pos]; i++)
		if(ahoscr[go[state][i]] <= rem)
			ret = (ret + dp[go[state][i]][sz(num) - pos - 1][rem - ahoscr[go[state][i]]]) % Mod;
	ret = (ret + dplow(num, pos + 1, go[state][num[pos]], rem - ahoscr[go[state][num[pos]]])) % Mod;
	return ret;
}

LL calc(vector<int> &num){
	LL ret = 0;
	for(int len = 1; len < sz(num); len++)
		for(int i = 1; i < m; i++)
			if(ahoscr[go[0][i]] <= k)
				ret = (ret + dp[go[0][i]][len - 1][k - ahoscr[go[0][i]]]) % Mod;
	ret = (ret + dplow(num)) % Mod;
	return ret;
}

bool isok(vector<int> &num){
	int rem = k;
	int sta = 0;
	for(int i = 0; i < sz(num); i++){
		rem -= ahoscr[go[sta][num[i]]];
		sta = go[sta][num[i]];
	}
	return rem >= 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(go, -1, sizeof go);
	cin >> n >> m >> k;
	{
		int sz;
		cin >> sz;
		for(int i = 0; i < sz; ++i){
			int val;
			cin >> val;
			lnum.PB(val);
		}
		cin >> sz;
		for(int i = 0; i < sz; ++i){
			int val;
			cin >> val;
			rnum.PB(val);
		}
	}
	for(int i = 0; i < n; i++){
		int sz;
		cin >> sz;
		while(sz--){
			int val;
			cin >> val;
			num[i].PB(val);
		}
		cin >> scr[i];
	}
	for(int i = 0; i < n; i++){
		int ptr = 0;
		for(auto val : num[i]){
			int &g = go[ptr][val];
			if(g == -1)
				g = sz++;
			ptr = g;
		}
		ahoscr[ptr] += scr[i];
	}
	for(int i = 0; i < m; i++)
		if(go[0][i] == -1)
			go[0][i] = 0;
		else
			q.push(go[0][i]);
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(int i = 0; i < m; i++){
			int v = go[u][i];
			if(~v){
				fail[v] = go[fail[u]][i];
				ahoscr[v] += ahoscr[fail[v]];
				q.push(v);
			}
			else
				go[u][i] = go[fail[u]][i];
		}
	}
	for(int i = 0; i < sz; i++)
		for(int j = 0; j <= k; j++)
			dp[i][0][j] = 1;
	for(int len = 1; len <= 200; len++)
		for(int i = 0; i < sz; i++)
			for(int j = 0; j <= k; j++)
				for(int alp = 0; alp < m; alp++)
					if(ahoscr[go[i][alp]] <= j){
						dp[i][len][j] += dp[go[i][alp]][len - 1][j - ahoscr[go[i][alp]]];
						if(dp[i][len][j] >= Mod)
							dp[i][len][n] -= Mod;
					}
	//calc(rnum);
	cout << ((calc(rnum) - calc(lnum) + isok(rnum))%Mod+Mod) % Mod << endl;
	return 0;
}
