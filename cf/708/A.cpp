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

void shift(int l, int r){
	for(int i = l; i < r; i++)
		s[i]--;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int ptr = 0;
	while(ptr < sz(s) and s[ptr] == 'a') ptr++;
	if(ptr == sz(s)){
		s.pop_back();
		cout << s << 'z' << '\n';
		return 0;
	}
	int ptr2 = ptr;
	while(ptr2 < sz(s) and s[ptr2] != 'a') ptr2++;
	shift(ptr, ptr2);
	cout << s << '\n';
	return 0;
}
