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

const int maxn = 30;
LL dp[maxn][maxn][maxn][maxn],
   pd[maxn][maxn][maxn][maxn],
   sumdp1[maxn],
   sumpd1[maxn],
   sumdp2[maxn][maxn][maxn],
   sumpd2[maxn][maxn][maxn];
int vc, ve, cc, ce;
bool ananan = true;
bool sedarr[maxn * maxn];
int ordarr[maxn * maxn];
string sedas, bises;
string s;

int ordof(char c){
	if(ananan){
		sedas = "aeiou";
		bises = "bcdfghjklmnpqrstvwxyz";
		for(int i = 'a'; i <= int('z'); i++){
			if(find(all(sedas), i) == sedas.end())
				ordarr[i] = find(all(bises), i) - bises.begin();
			else{
				sedarr[i] = true;
				ordarr[i] = find(all(sedas), i) - sedas.begin();
			}
		}
		ananan = false;
	}
	return ordarr[int(c)];
}

bool sedar(char c){
	ordof(c);
	return sedarr[c];
}

void updp(int i, int j, int k, char c){
	int l = ordof(c);
	if(j == 1){
		dp[i][j][k][l] = sumpd1[i - 1];
		sumdp1[i] += dp[i][j][k][l];
		sumdp2[i][j][l] += dp[i][j][k][l];
		return;
	}
	if(k == 1){
		for(auto cc : sedas)
			if(cc != c)
				dp[i][j][k][l] += sumdp2[i - 1][j - 1][ordof(cc)];
		sumdp1[i] += dp[i][j][k][l];
		sumdp2[i][j][l] += dp[i][j][k][l];
		return;
	}
	dp[i][j][k][l] = dp[i - 1][j - 1][k - 1][l];
	sumdp1[i] += dp[i][j][k][l];
	sumdp2[i][j][l] += dp[i][j][k][l];
	return;
}

void uppd(int i, int j, int k, char c){
	int l = ordof(c);
	if(j == 1){
		pd[i][j][k][l] = sumdp1[i - 1];
		sumpd1[i] += pd[i][j][k][l];
		sumpd2[i][j][l] += pd[i][j][k][l];
		return;
	}
	if(k == 1){
		for(auto cc : bises)
			if(cc != c)
				pd[i][j][k][l] += sumpd2[i - 1][j - 1][ordof(cc)];
		sumpd1[i] += pd[i][j][k][l];
		sumpd2[i][j][l] += pd[i][j][k][l];
		return;
	}
	pd[i][j][k][l] = pd[i - 1][j - 1][k - 1][l];
	sumpd1[i] += pd[i][j][k][l];
	sumpd2[i][j][l] += pd[i][j][k][l];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> ve >> vc >> ce >> cc
		>> s;
	if(s[0] == '*'){
		for(int i = 0; i < 21; i++)
			pd[0][1][1][i] = sumpd2[0][1][i] = 1;
		sumpd1[0] = 21;
		for(int i = 0; i < 5; i++)
			dp[0][1][1][i] = sumdp2[0][1][i] = 1;
		sumdp1[0] = 5;
	}
	else if(sedar(s[0])){
		dp[0][1][1][ordof(s[0])] = 1;
		sumdp1[0] += dp[0][1][1][ordof(s[0])];
		sumdp2[0][1][ordof(s[0])] += dp[0][1][1][ordof(s[0])];
	}
	else{
		pd[0][1][1][ordof(s[0])] = 1;
		sumpd1[0] += pd[0][1][1][ordof(s[0])];
		sumpd2[0][1][ordof(s[0])] += pd[0][1][1][ordof(s[0])];
	}
	for(int i = 1; i < sz(s); i++){
		if(s[i] != '*'){
			if(sedar(s[i])){
				for(int j = 1; j <= vc; j++)
					for(int k = 1; k <= min(j, ve); k++)
						updp(i, j, k, s[i]);
			}
			else
				for(int j = 1; j <= cc; j++)
					for(int k = 1; k <= min(j, ce); k++)
						uppd(i, j, k, s[i]);
			continue;
		}
		//dp
		for(int j = 1; j <= vc; j++)
			for(int k = 1; k <= min(j, ve); k++)
				for(auto c : sedas)
					updp(i, j, k, c);
		//pd
		for(int j = 1; j <= cc; j++)
			for(int k = 1; k <= min(j, ce); k++)
				for(auto c : bises)
					uppd(i, j, k, c);
	}
	LL ans = 0;
	for(int j = 1; j <= vc; j++)
		for(int k = 1; k <= min(j, ve); k++)
			for(auto c : sedas)
				ans += dp[sz(s) - 1][j][k][ordof(c)];
	for(int j = 1; j <= cc; j++)
		for(int k = 1; k <= min(j, ce); k++)
			for(auto c : bises)
				ans += pd[sz(s) - 1][j][k][ordof(c)];
	cout << ans << endl;
	return 0;
}
