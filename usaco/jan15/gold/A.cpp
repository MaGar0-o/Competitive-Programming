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

const int n = 1005;
int cnt[n+1][n+1],
	sum[n+1][n+1],
	up[n+1][n+1],
	dn[n+1][n+1],
	Max=1, ans, K;
pii a[n];

int count(int i1, int i2, int j1, int j2){
	i1--, j1--;
	return sum[i2][j2] - sum[i1][j2] - sum[i2][j1] + sum[i1][j1];
}

int arof(int i1, int i2, int j1, int j2){
	int xmn = 100000, xmx = 0,
		ymn = 100000, ymx = 0;
	for(int i = 0; i < K; i++)
		if(a[i].L >= i1 and a[i].L <= i2 and a[i].R >= j1 and a[i].R <= j2){
			smin(xmn, a[i].L);
			smax(xmx, a[i].L);
			smin(ymn, a[i].R);
			smax(ymx, a[i].R);
		}
	return (xmx - xmn) * (ymx - ymn);
}

int main(){
	ifstream cin("cowrect.in");
	ofstream cout("cowrect.out");
	cin >> K;
	for(int i = 0; i < K; i++){
		int fi, se;
		char th;
		cin >> fi >> se >> th;
		fi++, se++;
		a[i] = {fi, se};
		cnt[fi][se] = 1 - 2 * (th == 'G');
	}
	for(int i = 0; i <= n; i++)
		cnt[0][i] = cnt[i][0] = cnt[n][i] = cnt[i][n] = -1;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++){
			sum[i][j] = cnt[i][j];
			if(i) sum[i][j] += sum[i - 1][j];
			if(j) sum[i][j] += sum[i][j - 1];
			if(i and j) sum[i][j] -= sum[i - 1][j - 1];
		}
	for(int i = 1; i < n; i++)
		for(int j = 0; j < n; j++)
			up[i][j] = (cnt[i][j] != -1) * (up[i - 1][j] + 1);
	for(int i = n - 1; i > 0; i--)
		for(int j = 0; j < n; j++)
			dn[i][j] = (cnt[i][j] != -1) * (dn[i + 1][j] + 1);
	for(int i = 1; i < n; i++)
		for(int j = 0; j < n; j++){
			int p = j + 1;
			int umn = 100000,
				dmn = 100000;
			while(cnt[i][p] != -1){
				smin(umn, up[i][p]);
				smin(dmn, dn[i][p]);
				int CNT = count(i - umn + 1, i + dmn - 1, j+1, p);
				if(CNT > Max){
					Max = CNT;
					ans = arof(i - umn + 1, i + dmn - 1, j+1, p);
				}
				else if(CNT == Max)
					smin(ans, arof(i - umn + 1, i + dmn - 1, j+1, p));
				p++;
			}
			j = p - 1;
		}
	cout << Max << endl
		<< ans << endl;
	return 0;
}
