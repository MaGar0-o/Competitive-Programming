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

const int maxn = 4000 + 20,
	  maxq = 2e5 + 85 - 69;
int a1[maxn][maxn],
	e1[maxn][maxn],
	s[maxn][maxn],
	s2[maxn],ans;
int q1[maxq],
	q2[maxq],
	q3[maxq],
	q4[maxq],
	q5[maxq],
	q6[maxq];
int n, m, q;

void add1(int i, int j, int val){
	a1[i][j] += val;
}

void ers1(int i, int j, int val){
	e1[i][j] += val;
}
void add2(int i, int j, int val){
	a1[i][j] += val;
}

void ers2(int i, int j, int val){
	e1[i][j] += val;
}


void calc1(void){
	for(int j = 0; j < m; j++)
		for(int i = 0; i < n; i++){
			s[i][j] = a1[i][j] + e1[i][j];
			if(i) s[i][j] += s[i - 1][j];
			if(i) a1[i - 1][j + 1] += a1[i][j];
			e1[i][j + 1] += e1[i][j];
		}
}
void calc2(void){
	for(int j = m-1; j >=1; j--)
		for(int i = 0; i < n; i++){
			s2[i] = a1[i][j] + e1[i][j];
			if(i) s2[i] += s2[i - 1] ;
			if(i) a1[i - 1][j - 1] += a1[i][j];
			e1[i][j - 1] += e1[i][j];
			ans=ans+bool(s2[i]+s[i][j]);
		}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	n += 10, m += 10;
	for(int i = 0; i < q; i++){
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		a += 5, b += 5, c += 5, d += 5, e += 5 , f += 5;
		q1[i] = a, q2[i] = b, q3[i] = c, q4[i] = d, q5[i] = e, q6[i] = f;
		add1(a,b,+1);
		ers1(d+1,b,-1);

		int x = (b + c) / 2;
		add1(a - (x - b) - 1, x + 1, -1);
		ers1(d + 1, x + 1, +1);
		
		x = (e + f) / 2; //
		add1(d, e + 1, -1);
		ers1(d + 1, e + 1, +1);
		add1(d - (x - e), x + 1, +1);
		ers1(d + 1, x + 1, -1);

			
	}
	calc1();
	memset(a1, 0, sizeof e1);
	memset(e1, 0, sizeof a1);
	for(int i = 0; i < q; i++){
		int a, b, c, d, e, f;
		a = q1[i], b = q2[i], c = q3[i], d = q4[i], e = q5[i], f = q6[i];

		add2(a,c,+1);
		ers2(d+1,c,-1);

		int x = (b + c) / 2+1;
		add2(a - (c - x) - 1, x - 1, -1);
		ers2(d + 1, x - 1, +1);
		
		x = (e + f) / 2+1; //
		add2(d, f - 1, -1);
		ers2(d + 1, f - 1, +1);
		add2(d - (f - x), x - 1, +1);
		ers2(d + 1, x - 1, -1);
	}
	calc2();
	cout << ans << '\n';
	return 0;
}
