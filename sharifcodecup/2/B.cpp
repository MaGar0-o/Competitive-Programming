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

string s;

bool ispow(int l, int r, bool an = false){
	if(l >= r)
		return false;
	if(s[l] == '+' or s[l] == '-'){
		if(an)
			return false;
		return ispow(l + 1, r, true);
	}
	for(int i = l; i < r; i++)
		if(s[i] < '0' or s[i] > '9')
			return false;
	return true;
}

bool isbase(int l, int r, bool an = false){
	if(l >= r)
		return false;
	if(s[l] == '+' or s[l] == '-'){
		if(an)
			return false;
		return isbase(l + 1, r, true);
	}
	int id = find(s.begin() + l, s.begin() + r, '.') - s.begin();
	if(id == r)
		return ispow(l, r, true);
	return ispow(l, id, true) and ispow(id + 1, r, true);
}

bool isnum(int l, int r){
	r++;
	int id1 = find(s.begin() + l, s.begin() + r, 'e') - s.begin();
	int id2 = find(s.begin() + l, s.begin() + r, 'E') - s.begin();
	if(id1 != r)
		return isbase(l, id1) and ispow(id1 + 1, r);
	if(id2 != r)
		return isbase(l, id2) and ispow(id2 + 1, r);
	return isbase(l, r);
}

bool f(void){
	int p1 = 0;
	while(p1 < sz(s) and s[p1] == ' ') p1++;
	if(p1 == sz(s))
		return false;
	int p2 = sz(s) - 1;
	while(p2 >= 0 and s[p2] == ' ') p2--;
	return isnum(p1, p2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(getline(cin, s))
		cout << (f() ? "LEGAL" : "ILLEGAL") << endl;
	return 0;
}
