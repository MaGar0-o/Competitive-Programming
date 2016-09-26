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

const int maxn = 2e5 + 85 - 69;
LL a[maxn],
   b[maxn];
int n,
	coc, boz, cocnum, boznum, mancnt, yekcnt, sefcnt;

void naaa(void){
	cout << "No" << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		char tmp;
		cin >> a[i] >> tmp >> b[i];
		LL gcd = __gcd(abs(a[i]), b[i]);
		a[i] /= gcd;
		b[i] /= gcd;
		if(a[i] == 0) b[i] = 1;
		if(a[i] == 0) sefcnt++;
		else if(abs(a[i]) > b[i]) boz++, boznum = i;
		else if(abs(a[i]) < b[i]) coc++, cocnum = i;
		else if(a[i] == b[i]) yekcnt++;
		else if(a[i] == -b[i]) mancnt++;
	}
	if(boz > 1) naaa();
	if(coc > 1) naaa();
	if(mancnt > 1 and yekcnt == 0) naaa();
	if(boz and coc){
		if(abs(a[boznum] * b[cocnum]) != abs(a[cocnum] * b[boznum])) naaa();
		if(a[boznum] * b[cocnum] == -a[cocnum] * b[boznum] and mancnt == 0) naaa();
		if(a[boznum] * b[cocnum] == a[cocnum] * b[boznum] and yekcnt == 0) naaa();
	}
	if(mancnt and (coc or boz)) naaa();
	cout << "Yes" << endl;
	return 0;
}
