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
#define hash hsh

const int maxn = 40 + 5,
	  maxl = 2000 + 10;
const LL base = 313,
	  Mod = 1000LL * 1000 * 1000 + 9;
vector<int> q1, q2;
vector<LL> hash[maxn];
int dis[maxn][maxl],
	n;
LL P[maxl];
string s[maxn];

LL H(int id){
	return hash[id].back();
}

LL H(int id, int st, int en){
	return ((hash[id][en] - hash[id][st] * P[en - st]) % Mod + Mod) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < maxl; i++)
		P[i] = (P[i - 1] * base) % Mod;
	cin >> n;
	cin >> s[n] >> s[n]
		>> s[n + 1] >> s[n + 1];
	if(sz(s[n + 1]) > sz(s[n]))
		swap(s[n], s[n + 1]);
	if(s[n].substr(0, sz(s[n + 1])) != s[n + 1]){
		cout << "NIE\n";
		return 0;
	}
	for(int i = 0; i < n; i++)
		cin >> s[i] >> s[i];
	for(int i = 0; i <= n; i++){
		hash[i].PB(0);
		for(int j = 0; j < sz(s[i]); j++)
			hash[i].PB((hash[i].back() * base + s[i][j]) % Mod);
	}
	memset(dis, 63, sizeof dis);
	q1.PB(n);
	q2.PB(sz(s[n + 1]));
	dis[n][sz(s[n + 1])] = 0;
	for(int i = 0; i < sz(q1); i++){
		if(q2[i] == sz(s[q1[i]])){
			cout << dis[q1[i]][q2[i]] << '\n';
			return 0;
		}
		for(int j = 0; j < n; j++){
			if(sz(s[j]) <= sz(s[q1[i]]) - q2[i]){
				if(H(q1[i], q2[i], q2[i] + sz(s[j])) == H(j) and dis[q1[i]][q2[i] + sz(s[j])] >= 10 * 1000 * 1000){
					dis[q1[i]][q2[i] + sz(s[j])] = dis[q1[i]][q2[i]] + 1;
					q1.PB(q1[i]);
					q2.PB(q2[i] + sz(s[j]));
				}
			}
			else{
				int len = sz(s[q1[i]]) - q2[i];
				if(H(q1[i], q2[i], sz(s[q1[i]])) == H(j, 0, len) and dis[j][len] >= 10 * 1000 * 1000){
					dis[j][len] = dis[q1[i]][q2[i]] + 1;
					q1.PB(j);
					q2.PB(len);
				}
			}
		}
	}
	cout << "NIE\n";
	return 0;
}
