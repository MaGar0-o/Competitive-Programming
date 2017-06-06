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
#define next nxt

const int maxn = 400 + 10;
bool nans[maxn][maxn],
	 mark[maxn][maxn][maxn];
int next[maxn];
string s[maxn],
	   p[maxn];
int n, m, nn, mm;

bool equ(char c1, char c2){
	return c1 == c2 or c2 == '?';// or c1 == '?';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	cin >> nn >> mm;
	for(int i = 0; i < nn; i++){
		cin >> p[i];
		int match = 0;
		for(int j = 2; j <= mm; j++){
			while(match and !equ(p[i][j - 1], p[i][match]))
				match = next[match];
			match += equ(p[i][j - 1], p[i][match]);
			next[j] = match;
		}
		for(int ii = 0; ii < n; ii++){
			match = 0;
			for(int j = 0; j < mm + m; j++){
				while(match and !equ(s[ii][j % m], p[i][match]))
					match = next[match];
				match += equ(s[ii][j%m], p[i][match]);
				if(match == mm)
					mark[i][ii][((j - mm + 1) % m + m) % m] = true, match = next[match];
			}
		}
		/*cout << "#" << i << endl;
		for(int ii = 0; ii < n; ii++, cout << endl)
			for(int jj = 0; jj < m; jj++)
				cout << mark[i][ii][jj];
		cout << endl;
		*/
	}
	for(int i = 0; i < nn; i++)
		for(int ii = 0; ii < n; ii++)
			for(int jj = 0; jj < m; jj++)
				if(!mark[i][ii][jj])
					nans[((ii - i) % n + n) % n][jj] = true;
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < m; j++)
			cout << (nans[i][j] ? 0 : 1);
	return 0;
}
