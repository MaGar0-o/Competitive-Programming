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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s, t;
	cin >> n
		>> s
		>> t;
	for(int i = 0; i < n; i++)
		s[i] = (s[i] != t[i]);
	s.resize(unique(all(s)) - s.begin());
	n = s.size();
	if(n & 1){
		if(s[0] == 0)
			cout << (n - 1) / 2 << endl;
		else
			cout << (n + 1) / 2 << endl;
	}
	else
		cout << n / 2 << endl;
	return 0;
}
